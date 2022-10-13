#include <iostream>
using namespace std;

template <class T>
struct Node {
	T value;
	struct Node* next;
};
template <class T>
class LinkedList {
	public:
		struct Node<T>* head;
		LinkedList() {
			head = (struct Node<T>*) malloc(sizeof(struct Node<T>*));
			head->next = NULL;
		}
		insert(T value) {
			struct Node<T>* new_node = (struct Node<T>*) malloc(sizeof(struct Node<T>*));
			new_node -> value = value;
			new_node -> next = head -> next;
			head -> next = new_node;
		}
		remove () {
			if (head->next != NULL) {
				head -> next = head -> next -> next;
			}
		}
		sort () {
			struct Node<T>* temp;
			struct Node<T>* inner_temp;
			T swapVal;

			temp = head->next;
			while (temp != NULL) {
				inner_temp = temp->next;
				while (inner_temp != NULL) {
					if (temp->value > inner_temp->value) {
						// swapping values
						swapVal = temp->value;
						temp->value = inner_temp->value;
						inner_temp->value = swapVal;
					}
					inner_temp = inner_temp->next;
				}
				temp = temp->next;
			}
		}
		printList() {
			struct Node<T>* temp = head -> next;
			while (temp != NULL) {
				cout << temp -> value << endl;
				temp = temp -> next;
			}
		}
};

int main() {

	LinkedList<int> ll;

	ll.insert(34);
	ll.insert(56);
	ll.insert(12);

	ll.remove();

	ll.sort();

	ll.printList();

	return 0;
}
