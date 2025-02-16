#include "../Basic_Structure.h"
#include "../utils.h"
#include <iostream>


// 反转单链表
ListNode* reverseList(ListNode* head){
     ListNode* pre = nullptr;
     ListNode* next = nullptr;
     while(head!=nullptr){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
     }
     return pre;
}

// 反转双链表
BiListNode* reverseBiList(BiListNode* head){
    BiListNode* pre = nullptr;
    BiListNode* next = nullptr;
    while(head != nullptr){
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}

int main(){
    std::vector<int> arr = UTIL_H::genRandomArray(10, 0, 100);
    for(const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    ListNode* List = UTIL_H::genLinkList(arr);
    ListNode* cur = List;
    for(int i = 0; i < arr.size(); i++){
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    List = reverseList(List);
    ListNode* cur1 = List;
    for(int i = 0; i < arr.size(); i++){
        std::cout << cur1->val << " ";
        cur1 = cur1->next;
    }
    std::cout << std::endl;
}