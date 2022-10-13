from sqlalchemy import null


class Node:
	def __init__(self, value, next):
		self.value = value
		self.next = next

class Linkedlist:

	def __init__(self):
		self.head = Node(0, null)
	
	def insert(self, value, index=-1):
		if index < 0:
			# appending node at last
			current_node = self.head
			while True:
				if current_node.next == null:
					# last element here
					new_node = Node(value, null)
					current_node.next = new_node
					break
				current_node = current_node.next  # iterating to next node
		else:
			# appending node at index
			current_node = self.head
			for _ in range(index):
				current_node = current_node.next
			# ith ELEMENT HERE
			new_node = Node(value, current_node.next)
			current_node.next = new_node

	def delete(self, index=-1):
		if index < 0:
			# deleting last node
			current_node = self.head
			while True:
				if current_node.next.next == null:
					# last element here
					current_node.next = null
					break
				current_node = current_node.next  # iterating to next node
		else:
			# deleting node at index
			current_node = self.head
			for _ in range(index):
				current_node = current_node.next
			# ith ELEMENT HERE
			current_node.next = current_node.next.next

	def search(self, value):
		i = 0
		current_node = self.head.next
		while current_node != null:
			if current_node.value == value:
				return i
			current_node = current_node.next
			i += 1
		return False

	def printList(self):
		current_node = self.head
		while current_node.next != null:
			print(current_node.next.value)
			current_node = current_node.next



if __name__ == "__main__":
	ll = Linkedlist()
	ll.insert(23)
	ll.insert(75)
	ll.insert(10, 2)

	ll.delete(2)
	ll.search(75)

	ll.printList()