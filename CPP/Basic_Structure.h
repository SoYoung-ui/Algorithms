#ifndef BasicStructure

// 单链表节点
class ListNode{
    public:
    int val;
    ListNode* next;
    
    ListNode(int val){
        this->val = val;
    }

    ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};

// 双链表节点
class BiListNode{
    public:
    int val;
    BiListNode* last;
    BiListNode* next;

    BiListNode(int val){
        this->val = val;
    }

    BiListNode(int val, BiListNode* last, BiListNode* next){
        this->val = val;
        this->last = last;
        this->next = next;
    }
};
#endif