/*
	Linear Search
	Running Times:
		Worst Case -- O(n)
		Best Case -- O(1)
		Average Case -- O(n)

	Space: Worst -- O(1)
*/

int linearSearch(int array[], int length, int value) {
	for (int i = 0; i < length; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	// if not found
	return -1;
}