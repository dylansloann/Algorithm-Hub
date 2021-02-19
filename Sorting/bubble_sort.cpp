/*
	Bubble Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(n)
		Average Case -- O(n^2)

	Space: Worst -- O(1)
*/

void bubbleSort(int array[], int length) {
	int swapValue = array[0];
	bool swapPerformed = false;

	for (int i = 0; i < length; i++) {
		swapPerformed = false;
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapValue = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swapValue;
				swapPerformed = true;
			}
		}
		// break if no swaps made in previous iteration (sorted)
		if (swapPerformed == false) {
			break;
		}
	}
}