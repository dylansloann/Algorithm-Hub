#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(n)

int linearSearch(int array[], int length, int value) {
	for (int i = 0; i < length; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	// if not found
	return -1;
}





int main() {
	const int arrayLength = 10;
	int array[arrayLength] = {1, 5, 3, 8, 6, 7, 9, 2, 10, 4};

	int searchValue = 8;
	cout << "EXPECTED VALUE: 3" << endl;
	cout << linearSearch(array, arrayLength, searchValue) << endl;	
}