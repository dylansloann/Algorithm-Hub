#include <string>

// COMPLEXITY: Time - O(fullLengthString * subString)

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