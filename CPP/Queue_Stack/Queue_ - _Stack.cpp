#include <queue>
#include <stack>

// 两个栈实现队列
class MyStackQueue{
    public:
    std::stack<int> in;
    std::stack<int> out;
    
    MyStackQueue(){
        
    }

    void inToOut(){
        // out栈空时才能倒入数据
        if(out.empty()){
            // 若倒入数据, 必须将in栈倒空
            while(!(in.empty())){
                out.push(in.top());
                in.pop();
            }
        }
    }

    void push(int x){
        in.push(x);
        inToOut();
    }

    int pop(){
        inToOut();
        int ans = out.top();
        out.pop();
        return ans;
    }

    int peek(){
        inToOut();
        return out.top();
    }

    bool empty(){
        return in.empty() && out.empty();
    }
};


// 队列实现栈
class MyQueueStack{
    public:
    std::queue<int> queue;

    MyQueueStack(){

    }

    void push(int x){
        int n = queue.size();
        queue.push(x);
        for(int i = 0; i < n; i++){
            int ans = queue.front();
            queue.pop();
            queue.push(ans);
        }
    }

    int pop(){
        int ans = queue.front();
        queue.pop();
        return ans;
    }

    int top(){
        return queue.front();
    }

    bool empty(){
        return queue.empty();
    }
};