public class MyDeque<T> {

	private int max;
	private int front;
	private int rear;
	private T[] arr;

	MyDeque() { this(5); }
	MyDeque(int max) {
		this.max = max;
		front = -1;
		rear = -1;
		arr = (T[]) new Object[max];
	}

	public boolean isEmpty() {
		return (front == -1);
	}
	public boolean isFull() {
		return ( ( rear-front+max)%max == max-1  );
	}
	public void insertFront(T item) {
		if (isFull()) {
			System.out.println("OverFlow at Insertion"); return;
		}
		if (isEmpty()) {
			front = 1;
			rear = 0;
		}
		front = (front - 1 + max) % max;   // keeping it circular
		arr[front] = item;
	}
	public void insertRear(T item) {
		if (isFull()) {
			System.out.println("OverFlow at Insertion"); return;
		}
		if (isEmpty()) {
			front = 0;
			rear = -1;
		}
		rear = (rear + 1 + max) % max;   // keeping it circular
		arr[rear] = item;
	}
	void deleteFront() {
		if (isEmpty()) {
			System.out.println("Cannot remove from Empty Queue"); return;
		}
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			front = (front + 1) % max;
		}
	}
	void deleteRear() {
		if (isEmpty()) {
			System.out.println("Cannot remove from Empty Queue"); return;
		}
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			rear = (rear - 1 + max) % max;
		}
	}
	void printQueue() {
		if (isEmpty()) {
			System.out.println("Empty Queue"); return ;
		}
		int iters = ( rear-front+max ) % max;
		for (int i=0; i<=iters; i++) {
			System.out.println(  arr[ (front+i)%max ]  );
		}
	}

	public static void main(String[] args) {
		MyDeque<Integer> d = new MyDeque<Integer>();

		d.insertFront(34);
		d.insertFront(12);
		d.insertRear(120);
		d.deleteFront();
		d.deleteRear();
	
		d.printQueue();
	} 
}