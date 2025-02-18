class MyCircularDeque:
    

    def __init__(self, k: int):
        self.l = self.r = self.size = 0
        self.limit = k
        self.deque = [0] * k

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        else:
            if self.isEmpty():
                self.l = self.r = 0
                self.deque[0] = value
            else:
                self.l = self.limit - 1 if self.l == 0 else self.l - 1
                self.deque[self.l] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        else:
            if self.isEmpty():
                self.l = self.r = 0
                self.deque[0] = value
            else:
                self.r = 0 if self.r == self.limit - 1 else self.r + 1
                self.deque[self.r] = value
        self.size += 1
        return True
        
    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        else:
            self.l = 0 if self.l == self.limit - 1 else self.l + 1
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        else:
            self.r = self.limit - 1 if self.r == 0 else self.r - 1
        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.l]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.r]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.limit