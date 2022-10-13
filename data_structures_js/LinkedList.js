class Node {
	constructor(value=null, next=null) {
		this.value = value;
		this.next = next;
	}
}
class LinkedList {
	constructor () {
		this.head = new Node();
	}
	insert(value) {
		this.head.next = new Node(value, this.head.next);
	}
	delete() {
		if (this.head.next != null) {
			this.head.next = this.head.next.next;
		}
	}
	printList() {
		let temp = this.head.next;
		while (temp != null) {
			console.log(temp.value);
			temp = temp.next;
		}
	}
}

if (require.main == module) {
	ll = new LinkedList();
	ll.insert(34);
	ll.insert(4);
	ll.insert(14);
	ll.delete();

	ll.printList();
}