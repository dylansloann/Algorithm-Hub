#ifndef HASH_TABLE_H
#define HASH_TABLE_H

struct HashEntry {
	int key;
	int value;
	HashEntry(int key, int value) {
		this->key= key;
		this->value = value;
	}
};

class HashTable {
	private:
		HashEntry **table;
		int size;
	public:
		HashTable(int size);
		~HashTable();

		int hash(int key);
		int get(int key);
		void set(int key, int value);
		void remove(int key);
};


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

#endif