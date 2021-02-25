/*
	Bubble Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(n)
		Average Case -- O(n^2)

	Space: Worst -- O(1)
*/

void bubbleSort(int arr[], int length) {
	int swapValue = arr[0];
	bool swapPerformed = false;

	for (int i = 0; i < length; i++) {
		swapPerformed = false;
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swapValue = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swapValue;
				swapPerformed = true;
			}
		}
		// break if no swaps made in previous iteration (sorted)
		if (swapPerformed == false) {
			break;
		}
	}
}