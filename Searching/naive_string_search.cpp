/*
	Naive String Search
	Running Times:
		Worst Case -- O(fullLengthString * subString)
		Best Case -- O(fullLengthString * subString)
		Average Case -- O(fullLengthString * subString)

	Space: Worst -- O(1)
*/

#include <string>

int naiveSearch(std::string fullLengthString, std::string subString) {
	int total = 0;
	for (int i = 0; i < fullLengthString.length(); i++) {
		for (int j = 0; j < subString.length(); j++) {
			if (fullLengthString[i + j] != subString[j]) { break; }
			if (j == subString.length() - 1) { total++; }
		}
	}
	return total;
}