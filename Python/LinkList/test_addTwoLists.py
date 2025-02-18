# 两个链表相加
# 674 + 893
# 4 -> 7 -> 6
#      +
# 3 -> 9 -> 8
#      =
# 7 -> 6 -> 5 -> 1

# from .. import Basic_Structure
import sys
import os
# 将项目根目录添加到 Python 路径中
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from Basic_Structure import ListNode


def addTwoLists(List1: ListNode, List2: ListNode) -> ListNode:
    ans, cur = None, None
    carry = 0
    
    sum, val = 0, 0
    while List1 or List2:
        sum = (0 if List1 is None else List1.value) + (0 if List2 is None else List2.value)  + carry

        List1 = List1.next if List1 else None
        List2 = List2.next if List2 else None

        val = sum % 10
        carry = sum // 10
        if ans is None:
            ans = ListNode(val)
            cur = ans
        else:
            cur.next = ListNode(val)
            cur = cur.next
    
    if carry == 1:
        cur.next = ListNode(1);
    return ans

# 测试 342 + 465 = 807
l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))
result = addTwoLists(l1, l2)  # 7 → 0 → 8

print(str(result.value) + "->" + str(result.next.value) + "->" + str(result.next.next.value))
