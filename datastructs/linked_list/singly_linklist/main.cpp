#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

int main() {
	List temp_list1;

	temp_list1.push_back(25);
	temp_list1.push_back(40);
	temp_list1.push_back(8);
	temp_list1.push_back(23);
	temp_list1.push_back(43528);
	/* temp_list1.insert(87, 2);
	temp_list1.remove(40);
	temp_list1.remove_front();
	temp_list1.remove_back(); */
	List temp_list2 = temp_list1;

	temp_list1.display();
	temp_list2.display();
} 