#include "sorting.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <functional>


int main() {
    // 修正初始化语法
    std::vector<std::function<void(std::vector<int>&)>> algorithms;
    algorithms.push_back(SORTING_H::selectSort<int>);
    algorithms.push_back(SORTING_H::bubbleSort<int>);
    algorithms.push_back(SORTING_H::insertSort<int>);

    UTIL_H::comparator(algorithms, 500);
    return 0;
}