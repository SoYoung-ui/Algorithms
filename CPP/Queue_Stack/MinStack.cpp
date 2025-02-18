#include <stack>
// 设计一个能在常数时间内检索到最小元素的栈。

class MinStack{
    public:
    std::stack<int> data;
    std::stack<int> min;

    MinStack(){

    }

    void push(int val){
        data.push(val);
        if(min.empty() || val < min.top()){
            min.push(val);
        }else{
            min.push(min.top());
        }
    }

    void pop(){
        data.pop();
        min.pop();
    }

    int top(){
        return data.top();
    }

    int getMin(){
        return min.top();
    }

};