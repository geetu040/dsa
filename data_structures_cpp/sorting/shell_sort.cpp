#include <iostream>
#include <cmath>
using namespace std;

void print(int arr[], int size) {
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void shell_sort(int arr[], int size) {
	int gap = size / 2;
	
	for (gap; gap > 0; gap /= 2) {
		for (int i=0; i<size; i+=gap) {
			for (int j=i; j>=0; j-= gap) {
				if (i != j) {
					if (arr[j+1] > arr[j]) {
						break;
					} else {
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp; 
					}
				}
			}
		}
	}
}


int main() {

	int arr[] = {5, 3, 2, 1, 9, 4, 7, 22, 90, 21};
	int size = 10;

	print(arr, size);
	shell_sort(arr, size);
	print(arr, size);

}


