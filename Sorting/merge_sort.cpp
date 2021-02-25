/*
	Merge Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n*log(n))
		Best Case -- O(n*log(n))
		Average Case -- O(n*log(n))

	Space: Worst -- O(n)
*/

void merge(int arr[], int leftEnd, int mid, int rightEnd) {
	// new temp array sizes
	const int leftLength = mid - leftEnd + 1;
	const int rightLength = rightEnd - mid;

	// temp arrays
	int leftArray[leftLength];
	int rightArray[rightLength];

	// inserting data into left and right arr's
	for (int i = 0; i < leftLength; i++) {
		leftArray[i] = arr[i + leftEnd];
	}
	for (int i = 0; i < rightLength; i++) {
		rightArray[i] = arr[mid + i + 1];
	}

	// iterators
	int i = 0;
	int j = 0;
	int k = leftEnd;

	// MERGE left and right side
	while (i < leftLength && j < rightLength) {
		if (leftArray[i] < rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}

	// inserting remaining elements on either left or right
	while (i < leftLength) {
		arr[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < rightLength) {
		arr[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int leftEnd, int rightEnd) {
	if (leftEnd >= rightEnd) {return;}
	// calculates midpoint and left and rightl length's
	int mid = ((rightEnd + leftEnd) - 1) / 2;

	// recursively calls merge sort until base case is hit
	mergeSort(arr, leftEnd, mid);
	mergeSort(arr, mid + 1, rightEnd);

	merge(arr, leftEnd, mid, rightEnd);
}