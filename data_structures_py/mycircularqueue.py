class MyQueue:
	
	def __init__(self, max=5):
		self.max = max
		self.arr = []
		self.front = -1
		self.rear = -1

	def isEmpty(self):
		return (self.front == -1 and self.rear == -1);

	def isFull(self):
		return ((self.rear - self.front + self.max)%self.max == self.max - 1);

	def enQueue(self, item):
		if (self.isEmpty()):
			self.front = 0;
			self.rear = 0;
			self.arr.insert(self.front, item)
		
		elif (not self.isFull()):
			self.rear = (self.rear + 1) % self.max
			self.arr.insert(self.rear, item)
		
	def deQueue(self):
		if (self.front == self.rear) :
			self.front = -1;
			self.rear = -1;
		
		else:
			self.front = (self.front + 1) % self.max
		
	def printQueue(self):
		if (not self.isEmpty()):
			iters = ( self.rear-self.front+self.max ) % self.max
			for i in range(iters+1):
				print( self.arr[ (self.front+i)%self.max ] )
			

if __name__ == "__main__":
	mq = MyQueue()

	mq.enQueue(34)
	mq.enQueue(3)
	mq.enQueue(44)
	mq.enQueue(34)

	mq.deQueue()

	mq.printQueue()