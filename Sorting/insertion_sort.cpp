/*
	Insertion Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(max digits (n)
		Average Case -- O(n^2)

	Space: Worst -- O(1)
*/

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
