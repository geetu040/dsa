#include <iostream>
using namespace std;

template <class T=int>
class MyQueue {
	private:
		int front;
		int rear;
		int max;
		T* arr;

	public:
		MyQueue() : MyQueue(5) {}
		MyQueue(int max){
			MyQueue::max = max;
			rear = -1;
			front = -1;
			arr = new T[max];
		}
		int isEmpty() {
			return (front == -1 && rear == -1);
		}
		int isFull() {
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
					cout << arr[i] << endl;
				}
			}
		}
};

int main() {


	MyQueue<string> mq;
	
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





	return 0;
}