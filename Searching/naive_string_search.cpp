#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

// COMPLEXITY: Time - O(fullLengthString * subString)

int naiveSearch(string fullLengthString, string subString) {
	int total = 0;
	for (size_t i = 0; i < fullLengthString.length(); i++) {
		for (size_t j = 0; j < subString.length(); j++) {
			if (fullLengthString[i + j] != subString[j]) { break; }
			if (j == subString.length() - 1) { total++; }
		}
	}
	return total;
}





int main() {
	string sub = "hello";
	string fullLength = "I am having a great day, hello world, hello";

	cout << naiveSearch(fullLength, sub) << endl;
}