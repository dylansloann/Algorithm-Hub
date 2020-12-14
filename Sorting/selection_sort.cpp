#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n^2)

void selectionSort(int array[], int length) {
	int minIndex = 0, tempValue = 0;

	for (int i = 0; i < length; i++) {
		minIndex = i;
		// iterates to obtain minimum index
		for (int j = i + 1; j < length; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		/* swaps min to correct position in list if a 
		   change of the original minIndex was made */
		if (minIndex != i) {
			tempValue = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tempValue;
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
	selectionSort(array, arrayLength);
	printArray(array, arrayLength);
}	