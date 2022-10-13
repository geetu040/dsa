class MyQueue:

	def __init__(self, max=5):
		self.max = 5
		self.arr = []
		self.front = -1
		self.rear = -1

	def isEmpty(self):
		return (self.front == -1 and self.rear == -1);

	def isFull(self):
		return (self.rear - self.front == self.max - 1);

	def enQueue(self, item):
		if (self.isEmpty()):
			self.front = 0;
			self.rear = 0;
			self.arr.insert(self.front, item)
		
		elif (not self.isFull()):
			self.rear += 1;
			self.arr.insert(self.rear, item)
		
	def deQueue(self):
		if (self.front == self.rear) :
			self.front = -1;
			self.rear = -1;
		
		else :
			self.front += 1;
		
	def printQueue(self):
		if (not self.isEmpty()):
			for i in range(self.front, self.rear+1):
				print(self.arr[i])
			

if __name__ == "__main__":
	mq = MyQueue()

	mq.enQueue(34)
	mq.enQueue(3)
	mq.enQueue(44)
	mq.enQueue(34)

	mq.deQueue()

	mq.printQueue()