#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using std::cout, std::endl, std::vector, std::string;

// COMPLEXITY: Time - O(max digits (n * base))

int getDigitAtIndex(int number, int index) {
	int digit = floor(abs(number) / pow(10, index));
	return digit % 10;
}

int largestDigitAmount(int array[], int length) {
	unsigned int max = 0;
	for (int i = 0; i < length; i++) {
		string digits = std::to_string(array[i]);
		if (max < digits.length()) { max = digits.length(); }
	}
	return max;
}

void twoDimensionalVectorToArray(vector<std::vector<int>> vec, int arr[]) {
	int* iterator = arr;
	for (int i = 0; i < vec.size(); i++) {
		std::copy(vec[i].begin(), vec[i].end(), iterator);
		iterator += vec[i].size();
	}
}

void radixSort(int array[], int length) {
	int maxDigitAmount = largestDigitAmount(array, length);
	for (int i = 0; i < maxDigitAmount; i++) {
		// 2d vector for storing array items in correct "bucket"
		vector<vector<int>> digitBuckets;
		digitBuckets.resize(10);

		for (int j = 0; j < length; j++) {
			// calculates digit for correct indexing of digitBuckets
			int digit = getDigitAtIndex(array[j], i);
			digitBuckets[digit].push_back(array[j]);
		}
		/* updates our array with values correlating to to the 
		   item order and bucket order of digitBuckets */
		twoDimensionalVectorToArray(digitBuckets, array);
	}
}





void printArray(int array[], int length) {
	for (int i = 0; i < length - 1; i++) {
		cout << array[i] << " -- ";
	}
	cout << array[length - 1] << endl;
}

int main() {
	const int arrayLength = 10;
	int array[arrayLength] = {1, 5, 3, 8, 6, 7, 9, 2, 10, 4};

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	radixSort(array, arrayLength);
	printArray(array, arrayLength);
}	