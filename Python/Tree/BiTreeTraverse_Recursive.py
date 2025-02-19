import sys
import os
# 将项目根目录添加到 Python 路径中
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from Basic_Structure import BiTreeNode

# 先序遍历
def preOrder(T: BiTreeNode) -> list:
    if not T:
        return []
    return [T.value] + preOrder(T.left) + preOrder(T.right)

# 中序遍历
def inOrder(T: BiTreeNode) -> list:
    if not T:
        return []
    return inOrder(T.left) + [T.value] + inOrder(T.right)

# 后序遍历
def postOrder(T: BiTreeNode) -> list:
    if not T:
        return []
    return postOrder(T.left) + postOrder(T.right) + [T.value]