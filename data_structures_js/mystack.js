class MyStack {
	constructor(max=10) {
		this.max = max;
		this.arr = [];
		this.top = -1;
	}
	isEmpty() { return (this.top === -1); }
	isFull() { return (this.top === this.max-1); }
	push(item) {
		if (!this.isFull()) {
			this.arr.push(item)
			this.top++
		}
	}
	pop() {
		if (!this.isEmpty()) {
			this.top--
			return this.arr.pop();
		}
	}
	printStack() {
		for (let i=0; i<this.arr.length; i++) {
			console.log(this.arr[i])
		}
		console.log("-----")
	}
}

if (require.main === module) {
	ms = new MyStack();
	ms.push(10);
	ms.push(15);
	ms.push(20);
	ms.printStack();
	ms.pop();
	ms.pop();
	ms.printStack();
}