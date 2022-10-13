class MyQueue {
	
	constructor(max = 5) {
		this.max = max;
		this.front = -1;
		this.rear = -1;
		this.arr = [];
	}
	isEmpty() {
		return (this.front == -1 && this.rear == -1);
	}
	isFull() {
		return (this.rear - this.front == this.max - 1);
	}
	enQueue(item) {
		if (this.isEmpty()) {
			this.front = 0;
			this.rear = 0;
			this.arr[this.front] = item;
		} else if (!this.isFull()){
			this.rear += 1;
			this.arr[this.rear] = item;
		}
	}
	deQueue() {
		if (this.front == this.rear) {
			this.front = -1;
			this.rear = -1;
		} else {
			this.front += 1;
		}
	}
	printQueue() {
		if (!this.isEmpty()){
			for (let i=this.front; i<=this.rear; i++) {
				console.log(this.arr[i])
			}
		}
	}
}

if (require.main == module) {

	mq = new MyQueue();

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