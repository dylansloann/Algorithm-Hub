#include <iostream>

using std::cout, std::endl;

// COMPLEXITY: Time - O(log(n))

int binarySearch(int array[], int length, int value) {
	int startIndex = 0;
	int endIndex = length - 1;

	while (startIndex <= endIndex) {
		int middleIndex = startIndex + ((endIndex - startIndex) / 2);

		if (array[middleIndex] == value) {
			return middleIndex;
		} else if (array[middleIndex] < value) {
			startIndex = middleIndex + 1;
		} else {
			endIndex = middleIndex - 1;
		}
	}

	// if not found
	return -1;
}





int main() {
	int arrayLength = 10;
	int array[] = {12, 24, 34, 38, 45, 56, 74, 78, 89, 99};

	int searchValue = 38;
	cout << "EXPECTED VALUE: 3" << endl;
	cout << binarySearch(array, arrayLength, searchValue) << endl;
}