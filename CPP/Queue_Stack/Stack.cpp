#include <stack>

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