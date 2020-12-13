#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using std::cout, std::endl, std::vector, std::string;

// COMPLEXITY: Time - O(length of longest digit * amount of numbers)

int getDigitAtIndex(int number, int index) {
	int digit = floor(abs(number) / pow(10, index));
	return digit % 10;
}

int largestDigitAmount(int array[], size_t length) {
	unsigned int max = 0;
	for (size_t i = 0; i < length; i++) {
		string digits = std::to_string(array[i]);
		if (max < digits.length()) { max = digits.length(); }
	}
	return max;
}

void twoDimensionalvectorToArray(vector<std::vector<int>> vec, int arr[]) {
	int* iterator = arr;
	for (size_t i = 0; i < vec.size(); i++) {
		std::copy(vec[i].begin(), vec[i].end(), iterator);
		iterator += vec[i].size();
	}
}

void radixSort(int array[], size_t length) {
	size_t maxDigitAmount = largestDigitAmount(array, length);
	for (size_t i = 0; i < maxDigitAmount; i++) {
		vector<vector<int>> digitBuckets;
		digitBuckets.resize(10);
		for (size_t j = 0; j < length; j++) {
			int digit = getDigitAtIndex(array[j], i);
			digitBuckets[digit].push_back(array[j]);
		}
		twoDimensionalvectorToArray(digitBuckets, array);
	}
}




void printArray(int array[], size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		cout << array[i] << " -- ";
	}
	cout << array[length - 1] << endl;
}

int main() {
	const size_t arrayLength = 10;
	int array[arrayLength] = {1, 5, 3, 8, 6, 7, 9, 2, 10, 4};

	cout << "INTIAL ARRAY:" << endl;
	printArray(array, arrayLength);
	cout << endl << "SORTED ARRAY:" << endl;
	radixSort(array, arrayLength);
	printArray(array, arrayLength);
}	