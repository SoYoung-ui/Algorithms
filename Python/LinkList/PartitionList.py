import sys
import os
# 将项目根目录添加到 Python 路径中
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from Basic_Structure import ListNode

def PartitionList(head: ListNode, x: int):
    leftHead = leftTail = None
    rightHead = rightTail = None
    next = None

    while head:
        next = head.next
        head.next = None
        if(head.value < x):
            if(leftHead is None):
                leftHead = head
            else:
                leftTail.next = head
            leftTail = head
        else:
            if(rightHead is None):
                rightHead = head
            else:
                rightTail.next = head
            rightTail = head
        head = next
    if leftHead is None:
        return rightHead
    
    leftTail.next = rightHead
    return leftHead

List = ListNode(4, ListNode(5, ListNode(2, ListNode(1))))
result = PartitionList(List, 3)

print(result)