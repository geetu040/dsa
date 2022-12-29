#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void shuffle_array(int arr[], int n)
{
    // To obtain a time-based seed
    unsigned seed = 10;
    // Shuffling our array
    shuffle(arr, arr + n,
            default_random_engine(seed));
}
void print(float arr[], int size) {
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void print(int arr[], int size) {
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bucket_sort(float arr[], int size) {
	float bucket[size];
	for (int i=0; i<size; i++) {
		bucket[ (int) floor(arr[i]*size) ] = arr[i];
	}
	for (int i=0; i<size; i++) {
		arr[i] = bucket[i];
	}
}


int main() {

	int size = 13;
	int temp[size];
	float arr[size];

	for (int i=0; i<size; i++) { temp[i] = i; }
	int n = sizeof(temp) / sizeof(temp[0]);
	shuffle_array(temp, n);
	for (int i=0; i<size; i++) { arr[i] = temp[i]/(float)size; }

	print(arr, size);
	bucket_sort(arr, size);
	print(arr, size);

	return 0;
}


