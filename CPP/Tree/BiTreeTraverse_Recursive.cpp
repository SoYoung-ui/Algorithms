#include "../Basic_Structure.h"

#include <iostream>

// 二叉树的三种遍历顺序

void preOrder(BiTreeNode* T){
    if(T == nullptr){
        return;
    }
    std::cout << T->val << "-";
    preOrder(T->left);
    preOrder(T->right);
}

void inOrder(BiTreeNode* T){
    if(T == nullptr){
        return;
    }
    preOrder(T->left);
    std::cout << T->val << "-";
    preOrder(T->right);
}

void postOrder(BiTreeNode* T){
    if(T == nullptr){
        return;
    }
    preOrder(T->left);
    preOrder(T->right);
    std::cout << T->val << "-";
}

void f(BiTreeNode* T){
    if(T == nullptr){
        return;
    }
    // #1
    f(T);
    // #2
    f(T);
    // #3
    // 在函数调用栈中, 每个节点会出现3次, 3种不同的遍历顺序就对应了节点出现的第几次打印
}