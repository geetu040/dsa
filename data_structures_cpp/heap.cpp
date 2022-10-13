#include <iostream>
#include <vector>
using namespace std;

template<class T=int>
class Heap {
private:
	vector<T>* vec;
	void swap(int ind_1, int ind_2) {
		T temp = vec->at(ind_1);
		(*vec)[ind_1] = vec->at(ind_2);
		(*vec)[ind_2] = temp;
	}
public:
	Heap() {
		vec = new vector<int>();
	}
	void insert(T item) {
		vec->push_back(item);
		heapify();
	}
	void deleteNode(T item) {
		int i = -1;
		for (int j=0; j<vec->size()-1; j++) {
			if (item == vec->at(j)) {
				i = j;
				break;
			}
		}
		if (i != -1) {
			swap(
				i,
				vec->size()-1
			);
			vec->pop_back();
			heapify();
		}
	}
	void heapify() {
		heapify(vec->size()-1);
	}
	void heapify(int i) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int greatest = i;

		if (l < vec->size() && vec->at(l) > vec->at(greatest)) {
			greatest = l;
		}
		if (r < vec->size() && vec->at(r) > vec->at(greatest)) {
			greatest = r;
		}
		if (greatest != i) {
			swap(greatest, i);
			if (i != vec->size()-1) {
				heapify(vec->size()-1);
			}
		}
		if (i > 0) {
			heapify(i-1);
		}
	}
	void printHeap() {
		vector<int>::const_iterator cit;
		cout << "Heap Array --->   ";
		for (cit=vec->begin(); cit!=vec->end(); cit++){
			cout << *cit << "\t";
		}
		cout << endl;
	}

};

int main() {
	Heap<> p;
	p.insert(34);
	p.insert(343);
	p.insert(1);
	p.insert(2);
	p.insert(43);
	p.insert(23);
	p.insert(4);
	p.insert(9548);
	p.insert(66);
	p.insert(6546);
	p.insert(123);
	p.insert(43);
	p.insert(3);

	p.deleteNode(66);

	p.printHeap();

	return 0;
}