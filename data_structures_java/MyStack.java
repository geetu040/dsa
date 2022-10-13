class MyStack<T> {

	int max;
	T[] arr;
	int top;

	MyStack() {
		this(10);
	}
	MyStack(int max) {
		this.max = max;
		// arr = new T[max];
		arr = (T[]) new Object[max];
		top = -1;
	}
	boolean isEmpty() {
		if (top == -1) {
			return true;
		}
		return false;
	}
	boolean isFull() {
		if (top == max-1) {
			return true;
		}
		return false;
	}
	void push(T item) {
		if (!isFull()) {
			arr[++top] = item;
		}
	}
	T pop() {
		if (!isEmpty()) {
			return arr[top--];
		}
		return arr[0];
	}
	void printStack() {
		for (int i=0; i<=top; i++) {
			System.out.println(arr[i]);
		}
	}

	public static void main(String[] args){
		MyStack<String> ms = new MyStack<String>(5);
		System.out.println(ms.isEmpty());
		System.out.println(ms.isFull());

		ms.push("10fdfsdfs");
		ms.push("5fdfsdfs");
		ms.push("30fdfsdfs");
		ms.printStack();
		
		ms.pop();
		ms.pop();
		ms.pop();
		ms.printStack();
	}
}