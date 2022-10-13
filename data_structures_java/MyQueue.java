public class MyQueue<T> {
	
	private int front;
	private int rear;
	private int max;
	private T[] arr;

	MyQueue() {
		this(5);
	}
	MyQueue(int max) {
		this.max = max;
		front = -1;
		rear = -1;
		arr = (T[]) new Object[max];
	}
	public boolean isEmpty() {
		return (front == -1 && rear == -1);
	}
	public boolean isFull() {
		return (rear - front == max - 1);
	}
	void enQueue(T item) {
		if (isEmpty()) {
			front = 0;
			rear = 0;
			arr[front] = item;
		} else if (!isFull()){
			rear += 1;
			arr[rear] = item;
		}
	}
	void deQueue() {
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			front += 1;
		}
	}
	void printQueue() {
		if (!isEmpty()){
			for (int i=front; i<=rear; i++) {
				System.out.println(arr[i]);
			}
		}
	}

	public static void main(String[] args) {
		MyQueue<String> mq = new MyQueue<String>();

		mq.enQueue("34");
		mq.enQueue("14");
		mq.enQueue("394");
		mq.enQueue("4");
		mq.enQueue("77");
		mq.enQueue("12");   // won't be added since out of space
	
		mq.deQueue();
		mq.deQueue();
		mq.deQueue();
	
		mq.printQueue();

	}
}