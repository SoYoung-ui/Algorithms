#include "searching.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <functional>

// 暴力搜索
bool search(std::vector<int>& arr, int num){
    for(int& cur : arr){
        if(cur == num){
            return true;
        }
    }
    return false;
}

int main() {
    // 修正初始化语法
    std::vector<std::function<bool (std::vector<int>&, int)>> algorithms;
    algorithms.push_back(search);
    algorithms.push_back(SEARCH_H::binExist);

    UTIL_H::searchComparator(algorithms, 100000);
    return 0;
}