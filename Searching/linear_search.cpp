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