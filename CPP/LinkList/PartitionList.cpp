#include "../Basic_Structure.h"

// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置。
ListNode* PartitionList(ListNode* head, int x){
    // 使用4个指针, 分别标记小于区和大于区的两个端点
    ListNode* leftHead = nullptr;
    ListNode* leftTail = nullptr;
    ListNode* rightHead = nullptr;
    ListNode* rightTail = nullptr;
    // next指针用于防止断链
    ListNode* next = nullptr;
    while(head != nullptr){
        next = head->next;
        head->next = nullptr;
        if(head->val < x){
            if(leftHead == nullptr){
                leftHead = head;
            }else{
                leftTail->next = head;
            }
            leftTail = head;
        }else{
            if(rightHead == nullptr){
                rightHead = head;
            }else{
                rightTail->next = head;
            }
            rightTail = head;
        }
        head = next;
    }
    if(leftHead == nullptr){
        return rightHead;
    }
    leftTail->next = rightHead;
    return leftHead;
}