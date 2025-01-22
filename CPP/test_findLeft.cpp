#include <vector>
#include <functional>

#include "searching.h"
#include "utils.h"

int right(std::vector<int>& arr, int num){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] >= num){
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<std::function<int (std::vector<int>&, int)>> algorithms;
    algorithms.push_back(right);
    algorithms.push_back(SEARCH_H::findLeft);

    UTIL_H::searchComparator(algorithms, 100000);

}