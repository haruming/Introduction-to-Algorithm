#include <iostream>
#include <vector>
using namespace std;

vector<int> MAX_HEAPIFY(vector<int> arr, int i) {
	int left = i * 2 + 1;
	int right = (i + 1) * 2;
	int largest;
	if (left < arr.size() && arr[left] > arr[i]) {
		largest = left;
	} else {
		largest = i;
	}
	if (right < arr.size() && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		arr = MAX_HEAPIFY(arr, largest);
	}
	return arr;
}

vector<int> BUILD_MAX_HEAP(vector<int> arr) {
	for (int i = (arr.size()-1)/2; i >= 0; i--) {
		arr = MAX_HEAPIFY(arr, i);
	}
	return arr;
}

vector<int> HEAPSORT(vector<int> arr) {
	vector<int> result;
	arr = BUILD_MAX_HEAP(arr);
	for (int i = arr.size()-1; i >= 1; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		result.push_back(temp);
		arr.pop_back();
		arr = MAX_HEAPIFY(arr, 0);
	}
	result.push_back(arr[0]);
	return result;
}

int main() {
	int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	vector<int> arr(a, a+10);
	vector<int> result = HEAPSORT(arr);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
