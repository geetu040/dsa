#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {

	int pivot = arr[right];
	int pivotIndex = left;

	for (int i=left; i<=right; i++) {
		if (arr[i] <= pivot) {
			// swap i with pivot
			int temp = arr[i];
			arr[i] = arr[pivotIndex];
			arr[pivotIndex] = temp;
			// increment pivotIndex
			pivotIndex++;
		}
	}

	return pivotIndex-1;
}

void quick_sort(int arr[], int left, int right) {
	if (left >= right) {return;}

	int pivotIndex = partition(arr, left, right);
	quick_sort(arr, left, pivotIndex-1);
	quick_sort(arr, pivotIndex+1, right);
	
}


int main() {

	int arr[] = {40, 12, 54, 32, 1, 3, 2, 15};
	int j = 8;

	quick_sort(arr, 0, j-1);

	for (int i=0; i<j; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}