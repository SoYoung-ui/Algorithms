#include "../utils.h"
#include <iostream>
#include <algorithm>

using namespace std;
// 几个基本排序算法的实现19

/*  selectSort
    对于长度为n的数组
    找到[0, n-1]间的最小值，将其和0位置互换；
    找到[1, n-1]间的最小值，将其和1位置互换；
    ...
    找到[n-2, n-1]间的最小值，将其和n-2位置互换。

    for i = 0 : n-2
        minIdx = i
        for j = i+1 : n-1
            update minIdx
        swap(i, minIdx)
*/
void selectSort(vector<int>& arr){
    if(arr.size() < 2)  return;
    int n = arr.size();
    for(int i = 0; i < n-1; ++i){
        int minIdx = i;
        for(int j = i+1; j < n; ++j){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

/*  bubbleSort
    在[0, n-1]范围内，遍历找到最大的数移到n-1位置；
    在[0, n-2]范围内，遍历找到最大的数移到n-2位置；
    ...
    在[0, 1]范围内，找到最大的数移到1位置；

    flag = false;
    for i = n-1 : 1
        for j = 0 : i-1
            swap()
            flag = true
        if !flag    break
*/
void bubbleSort(vector<int>& arr){
    if(arr.size() < 2)  return;
    int n = arr.size();
    for(int i = n-1; i > 0; --i){
        // 每轮开始时重置标志位
        bool flag = false;
        for(int j = 0; j < i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

/*  insertSort
    对[0, 0]范围内进行排序；
    对[0, 1]范围内进行排序，使其有序，方法是将1位置的数向左移动直到左边的数小于等于它或左边没有数；
    对[0, 2]范围内使用同样方法排序；
    ...
    对[0, n-1]范围使用同样方法排序。

*/
void insertSort(vector<int>& arr){
    if(arr.size() < 2)  return;
    int n = arr.size();
    for(int i = 1; i < n; ++i){
        for(int j = i-1; j >= 0 && arr[j] > arr[j+1]; --j){
            swap(arr[j], arr[j+1]);
        }
    }
}

void comparator(int testTimes){
    // 数组长度在 45和55 之间随机
    int n = UTIL_H::getRandom(55, 45);
    int max = UTIL_H::getRandom(1000, 1);
    cout << "测试开始" << endl;
    for(int i = 0;i < testTimes; ++i){
        vector<int> arr1 = UTIL_H::genRandomArray(n, 1, max);
        vector<int> arr2 = arr1;
        vector<int> arr3 = arr1;

        selectSort(arr1);
        bubbleSort(arr2);
        insertSort(arr3);

        if(! (arr1 == arr2) || ! (arr1 == arr3)){
            cout << "测试失败" << endl;
        }
    }
    cout << "测试成功" << endl;
}

int main(){
    comparator(10000);
}