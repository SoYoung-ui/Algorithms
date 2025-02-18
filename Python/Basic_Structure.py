class ListNode:
    def __init__(self, value = 0, next = None):
        self.value = value;
        self.next = next;

    def __str__(self):
        values = []
        current = self
        while current:
            values.append(str(current.value))
            current = current.next
        return ' -> '.join(values)
