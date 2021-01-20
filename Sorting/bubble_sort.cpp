#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n^2)

void bubbleSort(int array[], int length) {
	int swapValue = array[0];
	bool swapPerformed = false;

	for (int i = 0; i < length; i++) {
		swapPerformed = false;
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapValue = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swapValue;
				swapPerformed = true;
			}
		}
		// break if no swaps made in previous iteration (sorted)
		if (swapPerformed == false) {
			break;
		}
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
	int array[arrayLength] = {1, 5, 3, 8, 6, 7, 9, 2, 10, 4};

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	bubbleSort(array, arrayLength);
	printArray(array, arrayLength);
}	