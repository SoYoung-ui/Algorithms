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

void inOrder(BiTreeNode* T){
    if(T == nullptr){
        return;
    }
    std::stack<BiTreeNode*> stack;
}