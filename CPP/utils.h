#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <functional>
#include <random>

#include "sorting.h"

// 随机数组的最大长度
#define N 100
// 随机数组中数的上界的范围
constexpr int upperRange[] = {500, 1000};
// 随机数组中数的下界的范围
constexpr int lowerRange[] = {-500, 0};

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
#endif