#include <iostream>
using namespace std;

void merge_sort(int arr[], int left, int right) {
	if (right == left) { return; }

	int n = right - left + 1;
	int mid = (n-1) / 2 + left;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);

	// MERGING
	int arr_temp[n];
	int left_temp = left;
	int right_temp = mid+1;

	for (int i=0; i<n; i++) {
		if (right_temp > right) {
			// add left
			arr_temp[i] = arr[left_temp++];
		}
		else if (left_temp > mid) {
			// add right
			arr_temp[i] = arr[right_temp++];
		}
		else {
			if (arr[left_temp] < arr[right_temp]) {
				// add left
				arr_temp[i] = arr[left_temp++];
			}
			else {
				// add right
				arr_temp[i] = arr[right_temp++];
			}
		}
	}
	// SWAPPING WITH NEW VALUES
	for (int i=0; i<n; i++) {
		arr[left+i] = arr_temp[i];
	}

}


int main() {

	int arr[] = {40, 12, 54, 32, 1, 3, 2, 55};
	int n = 8;

	merge_sort(arr, 0, n-1);
	
	for (int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}