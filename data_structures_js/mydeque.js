class MyDeque {
	constructor (max = 5) {
		this.max = max;
		this.front = -1;
		this.rear = -1;
		this.arr = [];
	}
	isEmpty() {
		return this.front == -1;
	}
	isFull() {
		return ( (this.rear-this.front+this.max)%this.max == this.max-1 );
	}
	insertFront(item) {
		if (this.isFull()) {
			console.log("OverFlow at Insertion");
			return;
		}
		if (this.isEmpty()) {
			this.front = 1;
			this.rear = 0;
		}
		this.front = (this.front - 1 + this.max) % this.max;   // keeping it circular
		this.arr[this.front] = item;

	}
	insertRear(item) {
		if (this.isFull()) {
			console.log("OverFlow at Insertion");
			return;
		}
		if (this.isEmpty()) {
			this.front = 0;
			this.rear = -1;
		}
		this.rear = (this.rear + 1 + this.max) % this.max;   // keeping it circular
		this.arr[this.rear] = item;
	}
	deleteFront() {
		if (this.isEmpty()) {
			console.log("Cannot remove from Empty Queue");
		}
		if (this.front == this.rear) {
			this.front = -1;
			this.rear = -1;
		} else {
			this.front = (this.front + 1) % this.max;
		}
	}
	deleteRear() {
		if (this.isEmpty()) {
			console.log("Cannot remove from Empty Queue");
		}
		if (this.front == this.rear) {
			this.front = -1;
			this.rear = -1;
		} else {
			this.rear = (this.rear - 1 + this.max) % this.max;
		}
	}
	printQueue() {
		if (this.isEmpty()) {
			console.log("Empty Queue"); return;
		}
		let iters = ( this.rear-this.front+this.max ) % this.max;
		for (let i=0; i<=iters; i++) {
			console.log( this.arr[ (this.front+i)%this.max ] )
		}
	}
}

if (require.main == module) {
	d = new MyDeque();

	d.insertFront(34);
	d.insertFront(12);
	d.insertRear(120);
	d.deleteFront();
	d.deleteRear();

	d.printQueue();

}