public class MyCircularQueue<T> {
	
	private int front;
	private int rear;
	private int max;
	private T[] arr;

	MyCircularQueue() {
		this(5);
	}
	MyCircularQueue(int max) {
		this.max = max;
		front = -1;
		rear = -1;
		arr = (T[]) new Object[max];
	}
	public boolean isEmpty() {
		return (front == -1 && rear == -1);
	}
	public boolean isFull() {
		return ((rear - front + max)%max == max - 1);
	}
	void enQueue(T item) {
		if (isEmpty()) {
			front = 0;
			rear = 0;
			arr[front] = item;
		} else if (!isFull()){
			rear = ( rear + 1 ) % max;
			arr[rear] = item;
		}
	}
	void deQueue() {
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			front = ( front + 1 ) % max;
		}
	}
	void printQueue() {
		if (!isEmpty()){
			int iters = ( rear-front+max ) % max;
			for (int i=0; i<=iters; i++) {
				System.out.println( arr[ (front+i)%max ] );
			}
		}
	}

	public static void main(String[] args) {
		MyCircularQueue<String> mq = new MyCircularQueue<String>();

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