#include <math.h>

// COMPLEXITY: Time - O(max digits (n + base))

const int base = 10;

int getDigitAtIndex(int number, int index) {
	int digit = number / pow(base, index);
    return digit % base;
}

void radixSort(int* arr, int n, int d) {
    int* output = new int[n];
    int* count = new int[base + 1];

    int i, j;
    for (int k = 0; k < d; k++) {
        // updates count (mid) array values
        for (i = 0; i <= base; i++) count[i] = 0;
        for (i = 0; i < n; i++) count[getDigitAtIndex(arr[i], k)]++;
        for (i = 1; i <= base; i++) count[i] += count[i - 1];

        // updates output array while decrementing count
        for (j = n - 1; j >= 0; j--) {
            i = count[getDigitAtIndex(arr[j], k)] - 1;
            output[i] = arr[j];
            count[getDigitAtIndex(arr[j], k)]--;
        }

        // copies values to update order
        for (i = 0; i < n; i++) arr[i] = output[i];
    }

    delete[] output;
    delete[] count;
}