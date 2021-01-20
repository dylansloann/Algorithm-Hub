#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n^2)

void insertionSort(int array[], int length) {
	for (int i = 1; i < length; i++) {
		int current = array[i];
		int j;
		// iterates to shift current to correct position
		for (j = i - 1; (array[j] > current) && (j >= 0); j--) {
			array[j + 1] = array[j];
		}
		array[j + 1] = current;
	}
}





void printArray(int array[], int length) {
	for (int i = 0; i < length - 1; i++) {
		cout << array[i] << " -- ";
	}
	cout << array[length - 1] << endl;
}

int main() {
	const int arrayLength = 10;
	int array[arrayLength] = {4, 5, 3, 8, 6, 7, 9, 2, 10, 1};

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	insertionSort(array, arrayLength);
	printArray(array, arrayLength);
}	