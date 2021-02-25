/*
	Bubble Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(n)
		Average Case -- O(n^2)

	Space: Worst -- O(1)
*/

void bubbleSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		bool swapPerformed = false;
		for (int j = 0; j < length - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapPerformed = true;
			}
		}
		// break if no swaps made in previous iteration (sorted)
		if (!swapPerformed) {
			break;
		}
	}
}