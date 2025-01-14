class Sorting:
    @staticmethod
    def select_sort(arr: list) -> None:
        if len(arr) < 2:
            return
        
        for i in range(len(arr) - 1):
            min_idx = i
            for j in range(i + 1, len(arr)):
                if arr[j] < arr[min_idx]:
                    min_idx = j
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    @staticmethod
    def bubble_sort(arr: list) -> None:
        if len(arr) < 2:
            return
        
        for i in range(len(arr) - 1, 0, -1):
            is_sorted = True
            for j in range(i):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    is_sorted = False
            if is_sorted:
                break
    
    @staticmethod
    def insert_sort(arr: list) -> None:
        if len(arr) < 2:
            return
        
        for i in range(1, len(arr)):
            j = i - 1
            while j >= 0 and arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                j -= 1 