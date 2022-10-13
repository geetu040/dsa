
class MyDeque():
	def __init__(self, max=5):
		self.front = -1
		self.rear = -1
		self.arr = [0]*max
		self.max = max

	def isEmpty(self):
		return (self.front == -1);

	def isFull(self):
		return ( (self.rear-self.front+self.max)%self.max == self.max-1 );

	def insertFront(self, item):
		if (self.isFull()):
			print("OverFlow at Insertion")
		
		if (self.isEmpty()):
			self.front = 1;
			self.rear = 0;
		
		self.front = (self.front - 1 + self.max) % self.max;   # keeping it circular
		self.arr[self.front] = item;
	
	def insertRear(self, item):
		if (self.isFull()):
			print("OverFlow at Insertion")
		
		if (self.isEmpty()):
			self.front = 0;
			self.rear = -1;
		
		self.rear = (self.rear + 1 + self.max) % self.max;   # keeping it circular
		self.arr[self.rear] = item;
	
	def deleteFront(self):
		if (self.isEmpty()):
			print("Cannot remove from Empty Queue")
			return
		
		if (self.front == self.rear):
			self.front = -1;
			self.rear = -1;
		else:
			self.front = (self.front + 1) % self.max;
		
	def deleteRear(self):
		if (self.isEmpty()):
			print("Cannot remove from Empty Queue")
			return
		
		if (self.front == self.rear):
			self.front = -1;
			self.rear = -1;
		else:
			self.rear = (self.rear - 1 + self.max) % self.max;
		
	def printQueue(self):
		if (self.isEmpty()):
			print("Empty Queue")
			return
		
		iters = ( self.rear-self.front+self.max ) % self.max;
		for i in range(iters+1):
			print( self.arr[ (self.front+i)%self.max ] )
		
	


if __name__ == "__main__":
	d = MyDeque()

	d.insertFront(34);
	d.insertFront(12);
	d.insertRear(120);
	d.deleteFront();
	d.deleteRear();

	d.printQueue();
