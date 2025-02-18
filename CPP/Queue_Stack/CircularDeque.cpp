#include <list>


class MyCircularDeque1{
    public:
    std::list<int> deque;
    int size, limit;

    MyCircularDeque1(int k){
        size = 0;
        limit = k;
    }

    bool insertFront(int value){
        if(isFull()){
            return false;
        } else {
            deque.push_front(value);
            size++;
            return true;
        }
    }

    bool insertLast(int value){
        if(isFull()){
            return false;
        } else {
            deque.push_back(value);
            size++;
            return true;
        }
    }

    bool deleteFront(){
        if(isEmpty()){
            return false;
        } else {
            deque.pop_front();
            size--;
            return true;
        }
    }

    bool deleteLast(){
        if(isEmpty()){
            return false;
        } else {
            deque.pop_back();
            size--;
            return true;
        }
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return deque.front();
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return deque.back();
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == limit;
    }

};

// 数组实现循环双端队列
class MyCircularDeque2{
    public:
    std::vector<int> deque;
    int l, r, size, limit;

    MyCircularDeque2(int k){
        deque.resize(k);
        l = r = 0;
        size = 0;
        limit = k;
    }

    bool insertFront(int value){
        if(isFull()){
            return false;
        } else {
            if(isEmpty()){
                l = r = 0;
                deque[0] = value;
            } else {
                l = l == 0 ? (limit - 1) : (l - 1);
                deque[l] = value;
            }
        }
        size++;
        return true;
    }

    bool insertLast(int value){
        if(isFull()){
            return false;
        } else {
            if(isEmpty()){
                l = r = 0;
                deque[0] = value;
            } else {
                r = r == (limit - 1) ? 0 : (r + 1);
                deque[r] = value;
            }
        }
        size++;
        return true;
    }

    bool deleteFront(){
        if(isEmpty()){
            return false;
        } else {
            l = (l == limit - 1) ? (0) : (l + 1);
        }
        size--;
        return true;
    }

    bool deleteLast(){
        if(isEmpty()){
            return false;
        } else {
            r = r == 0 ? (limit - 1) : r - 1;
        }
        size--;
        return true;
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return deque[l];
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return deque[r];
    }

    bool isFull(){
        return size == limit;
    }

    bool isEmpty(){
        return size == 0;
    }
};
