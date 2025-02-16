from .. import Basic_Structure
from Basic_Structure import ListNode


def mergeTwoLists(List1: ListNode, List2: ListNode) -> ListNode:
    if List1 is None or List2 is None:
        return List1 if List2 is None else List2
    
    head = List1 if List1.value <= List2.value else List2
    cur1 = head.next;
    cur2 = List2 if head is List1 else List1
    pre = head
    
    while cur1 is not None and cur2 is not None:
        if cur1.value <= cur2.value:
            pre.next = cur1
            cur1 = cur1.next
        else:
            pre.next = cur2
            cur2 = cur2.next
        pre = pre.next
    pre = cur2 if cur1 is None else cur1
    return head
