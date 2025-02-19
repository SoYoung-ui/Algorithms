import sys
import os
# 将项目根目录添加到 Python 路径中
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from Basic_Structure import BiTreeNode, Stack

def preOrder(T: BiTreeNode) -> list:
    if not T:
        return []
    stack = Stack()
    stack.push(T)
    ans = []
    while stack:
        T = stack.pop()
        ans.append(T.value)
        if T.right:
            stack.push(T.right)
        if T.left:
            stack.push(T.left)
    return ans

def inOrder(T: BiTreeNode) -> list:
    if T:
        stack = Stack()
        while not stack.is_empty() or T:
            
