#include <iostream>

using std::cout, std::endl;

void printArray(int array[], int length) {
	for (int i = 0; i < length - 1; i++) {
		cout << array[i] << " -- ";
	}
	cout << array[length - 1] << endl;
}

int main() {
	const int arrayLength = 8;
	int array[arrayLength] = {25, 64, 14, 98, 78, 109, 101, 34};

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	radixSort(array, arrayLength, 3);
	printArray(array, arrayLength);
}