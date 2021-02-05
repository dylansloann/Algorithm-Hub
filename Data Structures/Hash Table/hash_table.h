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

#endif