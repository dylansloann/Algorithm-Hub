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
