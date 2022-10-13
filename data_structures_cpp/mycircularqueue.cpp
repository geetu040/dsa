#include <iostream>
using namespace std;

template <class T=int>
class MyCircularQueue {
	private:
		int front;
		int rear;
		int max;
		T* arr;

	public:
		MyCircularQueue() : MyCircularQueue(5) {}
		MyCircularQueue(int max){
			MyCircularQueue::max = max;
			rear = -1;
			front = -1;
			arr = new T[max];
		}
		int isEmpty() {
			return (front == -1 && rear == -1);
		}
		int isFull() {
			return ((rear - front + max)%max == max - 1);
		}
		void enQueue(T item) {
			if (isEmpty()) {
				front = 0;
				rear = 0;
				arr[front] = item;
			} else if (!isFull()){
				// rear += 1;
                rear = ( rear + 1 ) % max;
				arr[rear] = item;
			}
		}
		void deQueue() {
			if (front == rear) {
				front = -1;
				rear = -1;
			} else {
				// front += 1;
				front = ( front + 1 ) % max;
			}
		}
		void printQueue() {
			if (!isEmpty()){
                cout << "front: " << front << endl ;
                cout << "rear: " << rear << endl ;

                int iters = ( rear-front+max ) % max;
                for (int i=0; i<=iters; i++) {
                    cout << arr[ (front+i)%max ] << endl;
                }
			}
		}
};

int main() {


	MyCircularQueue<int> mq;
	
    mq.enQueue(10);
    mq.enQueue(20);
    mq.enQueue(30);
    mq.enQueue(40);
    mq.enQueue(50);
    mq.deQueue();
    mq.deQueue();
    mq.deQueue();
    mq.enQueue(60);
    mq.enQueue(70);
    // mq.enQueue(80);


	mq.printQueue();


	// mq.enQueue(34);
	// mq.enQueue(14);
	// mq.enQueue(394);
	// mq.enQueue(4);
	// mq.enQueue(77);
	// mq.enQueue(12);   // won't be added since out of space

	// mq.deQueue();
	// mq.deQueue();
	// mq.deQueue();

	// mq.printQueue();





	return 0;
}