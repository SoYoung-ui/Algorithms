#include <iostream>

/*  在有序数组中确定num是否存在

*/

bool Binary_Search(std::vector<int>& arr, int num){
    if(arr.size() == 0) return false;
    int l = 0, r = arr.size()-1, m = 0;
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

/*  在有序数组中找到大于等于num的最左位置
    ans = -1;
    如果中点位置的值大于等于num，则ans等于中点位置，向左二分
    如果中点位置小于num，向右二分
*/ 
int Binary_findLeft(std::vector<int>& arr, int num){
    if(arr.size() == 0) return -1;
    int ans = -1, l = 0, r = arr.size()-1, m = 0;
    while(l <= r){
        m = (l+r)/2;
        if(arr[m] >= num){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return ans;
}

/*  在有序数组中找到小于等于num的最右位置
    ans = -1;
    如果中点位置的值小于等于num，则ans等于中点位置，向右二分
    如果中点位置大于num，向左二分
*/
int Binary_findRight(std::vector<int>& arr, int num){
    if(arr.size() == 0) return -1;
    int ans = -1, l = 0, r = arr.size()-1, m = 0;
    while(l <= r){
        m = (l + r)/2;
        if(arr[m] <= num){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return ans;
}

/*  求峰值(局部极大值)，对于无序数组，返回任意一个局部峰值的位置
    默认最左侧的元素的左边(即-1位置)为无穷小，最右侧的元素的右边(即n位置)为无穷大

    先判断第一个或最后一个是否为峰值，如果是则直接返回。
    如果不是，则说明1位置大于0位置([0,1]内递增)，且n-2位置大于n-1位置([n-2,n-1]内递减)。
    这说明在[1, n-2]内必定有峰值，考虑中点位置。
    1. 如果中点位置是峰值，直接返回；
	2. 如果中点左边元素值大于中点元素值，则说明`[1, (n-1)/2 - 1]`范围内必定有峰值；更新左右指针和中点，继续第1步；
	3. 如果中点右边元素值大于中点元素值，则说明`[(n-1)/2 + 1, n-2]`范围内必定有峰值；更新左右指针和中点，继续第1步；
	4. 如果中点左边和右边元素值都大于中点元素值，则说明`[1, (n-1)/2]`和`[(n-1)/2, n-2]`范围内都必定有峰值；更新左右指针和中点，继续第1步；

*/
int find_LocalMax(std::vector<int>& arr){
    if(arr.size() == 0) return -1;
    int n = arr.size();
    if(arr[0] > arr[1]){
        return 0;
    }
    if(arr[n-1] > arr[n-2]){
        return n-1;
    }
    int l = 1, r = n-2, m = 0, ans = -1;
    while(l <= r){
        m = (l + r)/2;   
        if(arr[m-1] > arr[m]){
            r = m-1;
        }else if(arr[m+1] > arr[m]){
            l = m + 1;
        }else{
            ans = m;
            break;
        }
    }
    return ans;
}