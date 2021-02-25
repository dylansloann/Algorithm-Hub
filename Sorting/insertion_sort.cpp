/*
	Insertion Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(max digits (n)
		Average Case -- O(n^2)

	Space: Worst -- O(1)
*/

void insertionSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		int current = arr[i];
		int j;
		// iterates to shift current to correct position
		for (j = i - 1; (arr[j] > current) && (j >= 0); j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = current;
	}
}
