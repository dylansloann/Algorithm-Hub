// COMPLEXITY: Time - O(n*log(n))

void swap(int array[], int firstIndex, int secondIndex) {
	int temp = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = temp;
}

int partion(int array[], int leftEnd, int rightEnd) {
	int pivot = array[leftEnd];
	int swapIndex = leftEnd;

	// moves all items that are less than pivot to the left
	for (int i = leftEnd + 1; i <= rightEnd; i++) {
		if (array[i] < pivot) {
			swapIndex++;
			swap(array, i, swapIndex);
		}
	}

	// swaps pivot with last item moved
	swap(array, leftEnd, swapIndex);
	return swapIndex;
}

void quickSort(int array[], int leftEnd, int rightEnd) {
	if (leftEnd >= rightEnd) { return; }
	int pivotIndex = partion(array, leftEnd, rightEnd);
	
	// recursively calls quickSort on left and right side of the pivotIndex
	quickSort(array, leftEnd, pivotIndex - 1);
	quickSort(array, pivotIndex + 1, rightEnd);
}