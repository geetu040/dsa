#include <iostream>
using namespace std;

template <class T = int>
class MyStack {
	public:
		int max;
		T *arr;
		int top;

		MyStack () {
			max = 10;
			arr = new T[max];
			top = -1;
		}

		int isFull() {
			if (top == max-1) { return 1; }
			return 0;
		}

		int isEmpty() {
			if (top == -1) { return 1; }
			return 0;
		}

		void push(T n) {
			if (!isFull()) { arr[ ++top ] = n; }
		}

		T pop() {
			if (!isEmpty()) { return arr[top--]; }
		}

		void printStack() {
			cout << "Printing Stacks: " << endl;
			for (int i=0; i<=top; i++) {
				cout << arr[i] << endl;
			}
		}
};

int main(){
	MyStack <char> ms;
	cout << "isFull: " << ms.isFull() << endl;
	cout << "isEmpty: " << ms.isEmpty() << endl;

	ms.push('a');
	ms.push('b');
	ms.push('c');
	ms.push('d');

	ms.printStack();
	ms.pop();
	ms.pop();
	ms.pop();
	ms.pop();
	ms.printStack();

	return 0;
}