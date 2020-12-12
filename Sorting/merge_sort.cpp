#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n*log(n))

void merge(int array[], int leftEnd, int mid, int rightEnd) {
	// new temp array sizes
	const size_t leftLength = mid - leftEnd + 1;
	const size_t rightLength = rightEnd - mid;

	// temp arrays
	int leftArray[leftLength];
	int rightArray[rightLength];

	// inserting data into left and right array's
	for (size_t i = 0; i < leftLength; i++) {
		leftArray[i] = array[i + leftEnd];
	}
	for (size_t i = 0; i < rightLength; i++) {
		rightArray[i] = array[mid + i + 1];
	}

	// iterators
	size_t i = 0;
	size_t j = 0;
	size_t k = leftEnd;

	// MERGE left and right side
	while (i < leftLength && j < rightLength) {
		if (leftArray[i] < rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}

	// inserting remaining elements on either left or right
	while (i < leftLength) {
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < rightLength) {
		array[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int leftEnd, int rightEnd) {
	if (leftEnd >= rightEnd) {return;}
	// calculates midpoint and left and rightl length's
	int mid = ((rightEnd + leftEnd) - 1) / 2;

	// recursively calls merge sort until base case is hit
	mergeSort(array, leftEnd, mid);
	mergeSort(array, mid + 1, rightEnd);

	merge(array, leftEnd, mid, rightEnd);
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
	mergeSort(array, left, right);
	printArray(array, arrayLength);
}	