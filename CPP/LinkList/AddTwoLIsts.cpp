// 两个链表相加
// 674 + 893
// 4 -> 7 -> 6
//      +
// 3 -> 9 -> 8
//      =
// 7 -> 6 -> 5 -> 1

#include <iostream>
#include "../Basic_Structure.h"

// 两个链表相加, 返回一个新的链表
ListNode* addTwoLists(ListNode* List1, ListNode* List2){
    // ans是新链表的头部
    ListNode* ans = nullptr;
    // cur用来创建新的链表
    ListNode* cur = nullptr;

    int carry = 0;
    for(
        int sum, val;
        List1 != nullptr || List2 != nullptr;    // 二者均为空时终止
        List1 = (List1 == nullptr) ? nullptr : List1->next,
        List2 = (List2 == nullptr) ? nullptr : List2->next
    ){
        sum = ((List1 == nullptr) ? 0 : List1->val)
            + ((List2 == nullptr) ? 0 : List2->val)
            + carry;
        
        val = sum % 10;     // 新节点的值
        carry = sum / 10;   // 进位的值

        if(ans == nullptr){
            ans = new ListNode(val);    // 创建出新链表的头部, 从此不再变化
            cur = ans;      // cur用来一步一步创建出新链表
        }else{
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        if(carry == 1){
            cur->next = new ListNode(1);
        }
        
    }
    return ans;
}