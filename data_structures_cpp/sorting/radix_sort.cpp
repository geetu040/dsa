#include <iostream>
using namespace std;

void print(int arr[], int size) {
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int get_max(int arr[], int size) {
	int max = -1;
	for (int i=0; i<size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
void countingSort(int arr[], int size, int d) {
	int max = 10;
	int count[max];
	int output[size];

	// preparing count array
	for (int i=0; i<max; i++) {
		count[i] = 0;
	}

	// counting items
	for (int i=0; i<size; i++) {
		count[ (arr[i] / d) % 10 ] += 1;
	}

	// commulative counting
	for (int i=1; i<max; i++) {
		count[i] = count[i] + count[i-1];
	}

	// sorting elemets based on place
	for (int i=size-1; i>=0; i--) {
		output[ count[ (arr[i] / d) % 10 ] - 1 ] = arr[i];
		count[ (arr[i] / d) % 10 ]--;
	}

	// replacing with the new sorted array for this place
	for (int i=0; i<size; i++) {
		arr[i] = output[i];
	}
}
void radix_sort(int arr[], int size) {
	int max = get_max(arr, size);
	for (int i=1; max/i > 0; i*=10) {
		countingSort(arr, size, i);
	}
}

int main() {

	int arr[] = {100, 3, 5, 2, 19, 7, 6, 2};
	int size = 8;
	
	print(arr, size);
	radix_sort(arr, size);
	print(arr, size);

	return 0;
}