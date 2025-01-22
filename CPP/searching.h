#ifndef SEARCH_H
#define SEARCH_H

#include <vector>


// 二分搜索, 在有序数组中确定num是否存在
bool binExist(std::vector<int>& arr, int num){
    if(arr.size() == 0) return false;
    int l = 0, r = arr.size() - 1, m = 0;
    while(l <= r){
        m = (l + r)/2;
        if(arr[m] == num){
            return true;
        }else if(arr[m] > num){
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return false;
}

// 在有序数组中找到大于等于num的首个数，返回其索引
int findLeft(std::vector<int>& arr, int num){
    if(arr.size() == 0) return false;
    int l = 0, r = arr.size() - 1, m = 0;
    int ans = -1;
    while(l <= r){
        m = (l + r)/2;  // 如果 l + r 非常大，相加会导致整型溢出
        // m = l + ((r - l) >> 1);
        if(arr[m] >= num){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}

#endif