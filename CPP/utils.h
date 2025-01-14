#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <functional>
#include <random>

// 随机数组的最大长度
#define N 100

// swap, 交换容器两个位置的数
template<typename T>
void swap(std::vector<T>& arr, int i, int j){
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 生成一个随机数
// 生成 [lowerBound, upperBound] 范围内的随机数
// lowerBound 默认为 0
int getRandom(int upperBound, int lowerBound = 0) {
    if (upperBound < lowerBound) {
        std::swap(upperBound, lowerBound);
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lowerBound, upperBound);
    return dis(gen);
}

// 生成随机数组
std::vector<int> genRandomArray(int size, int minVal, int maxVal) {
    if (size < 0) {
        throw std::invalid_argument("数组大小不能为负数");
    }
    
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = getRandom(maxVal, minVal);
    }
    return arr;
}

// 对数器
template<typename T>
void comparator(
    const std::vector<std::function<void(std::vector<T>&)>>& algorithms,
    int testTimes
) {
    int maxVal = getRandom(1000, 500);
    int minVal = getRandom(0, -500);
    std::cout << "测试开始！" << std::endl;
    for(int i = 0; i < testTimes; i++){
        // 结果数组
        std::vector<std::vector<T>> results;
        // 随机得到长度
        int size = getRandom(N-1);
        // 得到随机数组
        std::vector<T> arr = genRandomArray(size, minVal, maxVal);
        
        for(const auto& algo : algorithms){
            // 复制数组
            std::vector<T> arr_copy = arr;
            algo(arr_copy);  // 直接对数组进行排序
            results.push_back(arr_copy);  // 保存排序后的数组
        }

        // 对比测试结果
        bool allEqual = true;
        for(size_t j = 1; j < results.size(); ++j){
            if(results[j] != results[0]) {
                allEqual = false;
                break;
            }
        }

        // 如果结果不一致，输出错误信息
        if(!allEqual){
            std::cout << "测试失败！" << std::endl;
            return;
        }
    }
    std::cout << "测试通过！" << std::endl;
}

#endif