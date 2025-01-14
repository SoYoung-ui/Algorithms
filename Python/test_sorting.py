from sorting import Sorting
from test_utils import TestUtils

def main():
    algorithms = [
        Sorting.select_sort,
        Sorting.bubble_sort,
        Sorting.insert_sort
    ]
    
    TestUtils.comparator(algorithms)

if __name__ == "__main__":
    main()