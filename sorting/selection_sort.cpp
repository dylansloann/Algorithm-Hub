#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n^2)

void selectionSort(int array[], size_t length) {
	int minIndex = 0, tempValue = 0;

	for (size_t i = 0; i < length; i++) {
		minIndex = i;
		for (size_t j = i + 1; j < length; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			tempValue = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tempValue;
		}
	}
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

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	selectionSort(array, arrayLength);
	printArray(array, arrayLength);
}	