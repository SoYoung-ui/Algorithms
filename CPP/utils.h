#ifndef UTIL_H
#define UTIL_H

// swap
template<typename T>
void swap(T arr[], int i, int j){
    const T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

#endif