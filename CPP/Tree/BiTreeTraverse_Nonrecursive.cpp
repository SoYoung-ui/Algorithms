#include <iostream>
#include <stack>
#include "../Basic_Structure.h"

// 先序遍历
void preOrder(BiTreeNode* T){
    if(T == nullptr){
        return;
    }
    std::stack<BiTreeNode*> stack;
    stack.push(T);
    while(!stack.empty()){
        T = stack.top();
        stack.pop();
        std::cout << T->val << "-";
        if(T->right != nullptr){
            stack.push(T->right);
        }
        if(T->left != nullptr){
            stack.push(T->left);
        }
    }
}

// 1) 子树左指针依次进栈直到空
// 2) 栈弹出一个节点, 打印, 并对其右指针重复1)
// 3) 重复直到没有子树且栈为空
void inOrder(BiTreeNode* T){
    if(T != nullptr){
        std::stack<BiTreeNode*> stack;
        BiTreeNode* cur = T;
        while(!stack.empty() || cur != nullptr){
            if(cur != nullptr){
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
                std::cout << cur->val << " ";
                cur = cur->right;
            }
        }

    }
}

// 后序遍历, 使用两个栈实现, 思路类似先序遍历
void postOrderTwoStacks(BiTreeNode* T){
    if(T != nullptr){
        std::stack<BiTreeNode*> stack;
        std::stack<BiTreeNode*> collect;
        BiTreeNode* cur;
        stack.push(T);
        while(!stack.empty()){
            cur = stack.top();
            collect.push(cur);
            stack.pop();
            if(cur->left != nullptr){
                stack.push(cur->left);
            }
            if(cur->right != nullptr){
                stack.push(cur->right);
            }
        }
        while(!collect.empty()){
            std::cout << collect.top()->val << " ";
            collect.pop();
        }
    }
}

// 后序遍历, 一个栈
void postOrderOneStack(BiTreeNode* T){
    if(T != nullptr){
        std::stack<BiTreeNode*> stack;
        BiTreeNode* t = T;
        stack.push(t);
        // 如果没有打印过, t就一直是头节点
        // 一旦打印了, t就是上一个打印的节点
        while(!stack.empty()){
            BiTreeNode* cur = stack.top();
            if(cur->left != nullptr // 有左树且左树未被处理过
                && t != cur->left
                && t != cur->right
            ){
                stack.push(cur->left);
            } else if (cur->right != nullptr    // 有右树且右树未被处理过
                && t != cur->right
            ) {
                stack.push(cur->right);
            } else {
                std::cout << cur->val << " ";
                t = stack.top();
                stack.pop();
            }
        }
    }
}