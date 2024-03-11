## priority queue
## 1. insert
## 2. delete
## 3. getMin
## 4. extractMin
## 5. decreaseKey
## 6. increaseKey
## 7. deleteKey

class PriorityQueue:
    def __init__(self):
        self.queue = []
    
    def insert(self, value):
        self.queue.append(value)
        self.heapifyUp(len(self.queue) - 1)
    
    def delete(self, index):
        self.decreaseKey(index, float('-inf'))
        self.extractMin()
    
    def getMin(self):
        return self.queue[0]
    
    def extractMin(self):
        if len(self.queue) == 0:
            return
        self.queue[0] = self.queue[-1]
        self.queue.pop()
        self.heapifyDown(0)
    
    def decreaseKey(self, index, value):
        self.queue[index] = value
        self.heapifyUp(index)
    
    def increaseKey(self, index, value):
        self.queue[index] = value
        self.heapifyDown(index)
    
    def deleteKey(self, index):
        self.decreaseKey(index, float('-inf'))
        self.extractMin()
    
    def heapifyUp(self, index):
        parent = (index - 1) // 2
        if parent >= 0 and self.queue[parent] > self.queue[index]:
            self.queue[parent], self.queue[index] = self.queue[index], self.queue[parent]
            self.heapifyUp(parent)
    
    def heapifyDown(self, index):
        left = 2 * index + 1
        right = 2 * index + 2
        smallest = index
        if left < len(self.queue) and self.queue[left] < self.queue[smallest]:
            smallest = left
        if right < len(self.queue) and self.queue[right] < self.queue[smallest]:
            smallest = right
        if smallest != index:
            self.queue[smallest], self.queue[index] = self.queue[index], self.queue[smallest]
            self.heapifyDown(smallest)

pq = PriorityQueue()
pq.insert(3)
pq.insert(2)
pq.delete(1)
pq.insert(15)
pq.insert(5)
pq.insert(4)

## print the minimum value
print(pq.getMin())