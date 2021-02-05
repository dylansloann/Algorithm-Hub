#include "hash_table.h"
#include <iostream>

HashTable::HashTable(int size) {
	this->size = size;
	table = new HashEntry* [this->size];
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

HashTable::~HashTable() {
	for (int i = 0; i < size; i++) {
		if (table[i] != nullptr) {
		   delete table[i];
		}
	}
	delete[] table;
}

int HashTable::hash(int key) {
	return key % size;
}

int HashTable::get(int key) {
	int hashValue = hash(key);
	while (table[hashValue] != nullptr && table[hashValue]->key != key) {
		hashValue = hash(hashValue + 1);
	}

	// if null return
	if (table[hashValue] == nullptr) { return 0; }
	return table[hashValue]->value;
}

 

void HashTable::set(int key, int value) {
    int hashValue = hash(key);
    while (table[hashValue] != nullptr && table[hashValue]->key != key) {
    	hashValue = hash(hashValue + 1);
    }

    // delete previous and set new
    if (table[hashValue] != nullptr) { delete table[hashValue]; }
    table[hashValue] = new HashEntry(key, value);
}    

void HashTable::remove(int key) {
	int hashValue = hash(key);
	while (table[hashValue] != nullptr) {
		if (table[hashValue]->key == key) { break; }
		hashValue = hash(hashValue + 1);
	}

	// if null return;
	if (table[hashValue] == nullptr) { return; } 
	delete table[hashValue];
}

