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