import random
from typing import List, Callable

class TestUtils:
    @staticmethod
    def get_random_array(size: int, min_val: int = -500, max_val: int = 500) -> List[int]:
        return [random.randint(min_val, max_val) for _ in range(size)]
    
    @staticmethod
    def comparator(algorithms: List[Callable], test_times: int = 500) -> None:
        print("测试开始！")
        
        for _ in range(test_times):
            size = random.randint(0, 100)
            arr = TestUtils.get_random_array(size)
            
            results = []
            for algo in algorithms:
                arr_copy = arr.copy()
                algo(arr_copy)
                results.append(arr_copy)
            
            if not all(result == results[0] for result in results):
                print("测试失败！")
                return
                
        print("测试通过！") 