#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n*log(n))

void swap(int array[], int firstIndex, int secondIndex) {
	int temp = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = temp;
}

int partion(int array[], size_t leftEnd, size_t rightEnd) {
	int pivot = array[leftEnd];
	int swapIndex = leftEnd;

	for (size_t i = leftEnd + 1; i <= rightEnd; i++) {
		if (array[i] < pivot) {
			swapIndex++;
			swap(array, i, swapIndex);
		}
	}

	swap(array, leftEnd, swapIndex);
	return swapIndex;
}

void quickSort(int array[], int leftEnd, int rightEnd) {
	if (leftEnd >= rightEnd) { return; }
	int pivotIndex = partion(array, leftEnd, rightEnd);
	quickSort(array, leftEnd, pivotIndex - 1);
	quickSort(array, pivotIndex + 1, rightEnd);
}





void printArray(int array[], size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		cout << array[i] << " -- ";
	}
	cout << array[length - 1] << endl;
}

int main() {
	const size_t arrayLength = 10;
	int array[arrayLength] = {1, 5, 3, 8, 6, 7, 9, 2, 10, 4};

	int left = 0;
	int right = arrayLength - 1;

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	quickSort(array, left, right);
	printArray(array, arrayLength);
}	