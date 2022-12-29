#include <iostream>
using namespace std;

void print(int arr[], int size) {
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void pigeonhole_sort(int arr[], int size) {
	int min = arr[0];
	int max = arr[0];
	for (int i=0; i<size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int range = (max - min + 1);
	int hole[size];
	for (int i=0; i<range; i++) {
		hole[i] = 0;
	}

	for (int i=0; i<size; i++) {
		hole[ arr[i] - min ] = arr[i];
	}

	for (int i=0; i<range; i++) {
		arr[i] = hole[i];
	}

}


int main() {

	int arr[] = {5, 3, 2, 1, 9, 4, 7, 8, 6};
	int size = 9;

	print(arr, size);
	pigeonhole_sort(arr, size);
	print(arr, size);

}


