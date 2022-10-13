#include <iostream>
using namespace std;

template <class T = int>
class MyDeque {
	private:
		int max;
		int front;
		int rear;
		T* arr;
	public:
		MyDeque(): MyDeque(5) {}
		MyDeque(int max) {
			MyDeque::max = max;
			front = -1;
			rear = -1;
			arr = new T[max];
		}
		int isEmpty() {
			return (front == -1);
		}
		int isFull() {
			return ( (rear-front+max)%max == max-1 );
		}
		void insertFront(T item) {
			if (isFull()) {
				cout << "OverFlow at Insertion" << endl; return;
			}
			if (isEmpty()) {
				front = 1;
				rear = 0;
			}
			front = (front - 1 + max) % max;   // keeping it circular
			arr[front] = item;

		}
		void insertRear(T item) {
			if (isFull()) {
				cout << "OverFlow at Insertion" << endl; return;
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
				cout << "Cannot remove from Empty Queue" << endl; return;
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
				cout << "Cannot remove from Empty Queue" << endl; return;
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
				cout << "Empty Queue"; return;
			}
			int iters = ( rear-front+max ) % max;
			for (int i=0; i<=iters; i++) {
				cout << arr[ (front+i)%max ] << endl;
			}
		}
};

int main(){

	MyDeque<int> d;

	d.insertFront(34);
	d.insertFront(12);
	d.insertRear(120);
	d.deleteFront();
	d.deleteRear();

	d.printQueue();

	return 0;
}