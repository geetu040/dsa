class MyStack:

	def __init__(self, max=10):
		self.arr = []
		self.top = -1
		self.max = max

	def isEmpty(self):
		if self.top == -1:
			return True;
		return False;

	def isFull(self):
		if self.top == self.max-1:
			return True
		return False

	def push(self, item):
		if not self.isFull():
			self.top += 1
			self.arr.append(item)
	
	def pop(self):
		if not self.isEmpty():
			to_return = self.arr[self.top]
			del self.arr[self.top]
			self.top -= 1
			return to_return

	def printStack(self):
		for i in self.arr:
			print(i)


if __name__ == "__main__":
	ms = MyStack()

	ms.push(10)
	ms.push(14)
	ms.push(11)
	ms.printStack()

	ms.pop()
	ms.pop()
	ms.push(110)
	ms.printStack()
