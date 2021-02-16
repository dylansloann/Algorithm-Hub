// COMPLEXITY: Time - O(n + k))

void countingSort(int* arr, int n, int k) {
    int i, j;
    int* output = new int[n];
    int* count = new int[k+1];
    
    for (i = 0; i <= k; i++) count[i] = 0;
    for (j = 0; j < n; j++) count[arr[j]]++;
    for (i = 1; i <= k; i++) count[i] += count[i - 1];

    for (j = n - 1; j >= 0; j--) {
        i = count[arr[j]] - 1;
        output[i] = arr[j];
        count[arr[j]]--;
    }

    for (i = 0; i < n; i++) arr[i] = output[i]; 

    delete[] output;
    delete[] count;
}