/*
	Quick Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(n*log(n))
		Average Case -- O(n*log(n))

	Space: Worst -- O(logn)
*/

void swap(int arr[], int firstIndex, int secondIndex) {
	int temp = arr[firstIndex];
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
}

int partion(int arr[], int leftEnd, int rightEnd) {
	int pivot = arr[leftEnd];
	int swapIndex = leftEnd;

	// moves all items that are less than pivot to the left
	for (int i = leftEnd + 1; i <= rightEnd; i++) {
		if (arr[i] < pivot) {
			swapIndex++;
			swap(arr, i, swapIndex);
		}
	}

	// swaps pivot with last item moved
	swap(arr, leftEnd, swapIndex);
	return swapIndex;
}

void quickSort(int arr[], int leftEnd, int rightEnd) {
	if (leftEnd >= rightEnd) { return; }
	int pivotIndex = partion(arr, leftEnd, rightEnd);
	
	// recursively calls quickSort on left and right side of the pivotIndex
	quickSort(arr, leftEnd, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, rightEnd);
}