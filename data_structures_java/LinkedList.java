class Node<T> {
	T value;
	Node next;
	Node () {
		next = null;
	}
	Node (T value) {
		this(value, null);
	}
	Node (T value, Node next) {
		this.value = value;
		this.next = next;
	}
}

public class LinkedList<T> {
	Node<T> head;
	LinkedList () {
		head = new Node<T>();
	}
	public void insert(T value) {
		head.next = new Node<T>(value, head.next);
	}
	public void delete() {
		if (head.next != null) {
			head.next = head.next.next;
		}
	}
	public void printList() {
		Node<T> temp = head.next;
		while (temp != null) {
			System.out.println(temp.value);
			temp = temp.next;
		}
	}

	public static void main(String[] args) {
		LinkedList<Integer> ll = new LinkedList<Integer>();
		ll.insert(44);
		ll.insert(34);
		ll.insert(3);
		ll.delete();
		ll.insert(4);
		ll.insert(415);
		ll.printList();
	}
}