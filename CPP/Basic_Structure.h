#ifndef BasicStructure
#define BasicStructure

#include <queue>
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

// C++内置的队列
class CPPQueue{
    public:
    std::queue<int> queue;

    bool isEmpty(){
        return this->queue.empty();
    }

    void push(int num){
        this->queue.push(num);
    }

    int pop(){
        int front = this->queue.front();
        this->queue.pop();
        return front;
    }

    int size(){
        return this->queue.size();
    }

    int peek(){
        return this->queue.front();
    }
};

class MyQueue{
    public:
    std::vector<int> queue;
    int l, r;

    // n为入队操作的次数上限
    MyQueue(int n){
        queue.resize(n);
        l = 0;
        r = 0;
    }

    bool isEmpty(){
        return l == r;
    }

    bool isFUll(){
        return r >= queue.size();
    }

    void push(int num){
        if(this->isFUll()){
            throw std::runtime_error("Queue is Full");
        }
        queue[r++] = num;
    }

    int pop(){
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return queue[l++];
    }

    int front(){
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return queue[l];
    }

    int back(){
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return queue[r-1];
    }

    int size(){
        return r - l;
    }
};

class MyCircularQueue{
    public:
    std::vector<int> queue;
    int l, r, size, limit;
    // 同时在队列中的数字个数不超过k
    MyCircularQueue(int k){
        queue.resize(k);
        l = r = size = 0;
        limit = k;
    }

    bool enQueue(int num){
        if(isFull()){
            return false;
        }else{
            queue[r] = num;
            r = r == limit - 1 ? 0 : r + 1;
            size++;
            return true;
        }
    }

    bool deQueue(){
        if(isEmpty()){
            return false;
        }else{
            l = l == limit - 1 ? 0 : l + 1;
            size--;
            return true;
        }
    }

    int Front(){
        if(isEmpty()){
            return -1;
        }
        return queue[l];
    }

    int Rear(){
        if(isEmpty()){
            return -1;
        }
        int last = r == 0 ? (limit - 1) : (r - 1);
        return queue[last];
    }

    bool isFull(){
        return size == limit;
    }

    bool isEmpty(){
        return size == 0;
    }
};

class CPPStack{
    std::stack<int> stack;

    bool isEmpty(){
        return this->stack.empty();
    }

    void push(int num){
        this->stack.push(num);
    }

    int pop(){
        int t = this->stack.top();
        this->stack.pop();
        return t;
    }

    int peek(){
        return stack.top();
    }

    int size(){
        return stack.size();
    }
};

class MyStack{
    std::vector<int> stack;
    int size;

    MyStack(int n){
        this->stack.resize(n);
        this->size = 0;
    }

    bool isEmpty(){
        return this->size == 0;
    }

    void push(int num){
        stack[size++] = num;
    }

    int pop(){
        if(this->isEmpty()){
            throw std::runtime_error("Stack is Empty");
        }
        return stack[--size];
    }

    int peek(){
        return stack[size - 1];
    }

    int size(){
        return size;
    }
};



#endif