/*
	Selection Sort (Comparison-basd)
	Running Times:
		Worst Case -- O(n^2)
		Best Case -- O(n^2)
		Average Case -- O(n^2)

	Space: Worst -- O(1)
*/

void selectionSort(int array[], int length) {
	int minIndex = 0, tempValue = 0;

	for (int i = 0; i < length; i++) {
		minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		/* swaps min to correct position in list if a 
		   change of the original minIndex was made */
		if (minIndex != i) {
			tempValue = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tempValue;
		}
	}
}
