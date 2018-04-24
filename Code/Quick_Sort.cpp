#include<iostream>
using namespace std;

// partition for the array to find the pivot value and divide the array into 2 parts
// return the index of the pivot value or position in the middle
int PARTITION(int* arr, int p, int r) {
	int pivot = arr[r];
	int i = p - 1;
	for (int j = p; j <= r-1; j++) {
		if (arr[j] <= pivot) {
			i += 1;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = pivot;
	arr[r] = temp;
	return i+1;
}

// sort the array recursively
void QUICKSORT(int* arr, int p, int r) {
	if (p < r) {
		int q = PARTITION(arr, p, r);
		QUICKSORT(arr, p, q-1);
		QUICKSORT(arr, q+1, r);
	}
}

// entrance
int main() {
	int arr[] = {2,8,7,1,3,5,6,4};
	QUICKSORT(arr, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
} 
