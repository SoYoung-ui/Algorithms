#include <iostream>
#include "../Basic_Structure.h"

// 合并两个有序链表, 返回一个新链表
ListNode* mergeTwoLists(ListNode* List1, ListNode* List2){
    if(List1 == nullptr || List2 == nullptr){
        return List1 == nullptr ? List2 : List1;
    }
    // 较小链表的头部作为新链表的head, 这一步确定了新链表的第一个节点
    ListNode* head = List1->val <= List2->val ? List1 : List2;
    // cur1 成为较小链表的第一个节点
    ListNode* cur1 = head->next;
    // cur2 成为较大链表的第一个节点
    ListNode* cur2 = head == List1 ? List2 : List1;
    // pre始终指向新链表的最后一个节点
    ListNode* pre = head;
    while(cur1 != nullptr && cur2 != nullptr){
        if(cur1->val <= cur2->val){
            pre->next = cur1;
            cur1 = cur1->next;
        }else{
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }
    // 循环结束时, cur1 和 cur2 至少有一个为空
    pre->next = cur1 == nullptr ? cur2 : cur1;
    return head;
}