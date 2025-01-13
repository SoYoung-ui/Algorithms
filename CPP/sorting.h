// Sorting algorithms
#ifndef SORTING_H
#define SORTING_H

#include <vector>

#include "utils.h"

// selectSort
template<typename T>
void selectSort(std::vector<T>& arr){
    if(arr.size() < 2) return;
    for(int i = 0; i < arr.size()-1; i++){
        int minIndex = i;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        UTIL_H::swap(arr, i, minIndex);
    }
}

// bubbleSort
template<typename T>
void bubbleSort(std::vector<T>& arr){
    if(arr.size() < 2) return;
    for(int i = arr.size()-1; i > 0; i--){
        bool flag = false;  // 每轮开始时重置标志
        for(int j = 1; j <= i; j++){
            if(arr[j-1] > arr[j]){
                UTIL_H::swap(arr, j-1, j);
                flag = true;
            }
        }
        if(!flag){  // 如果这轮没有交换，说明已经有序
            break;
        }
    }
}
// insertSort
template<typename T>
void insertSort(std::vector<T>& arr){
    if(arr.size() < 2) return;
    for(int i = 1; i < arr.size(); i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[j] > arr[j+1]){
                UTIL_H::swap(arr, j, j+1);
            }else{
                break;
            }
        }
    }
}

#endif // SORTING_H