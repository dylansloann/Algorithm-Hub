#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <typename T>
struct HashEntry {
	int key;
	T value;
	HashEntry(int key, int value) {
		this->key= key;
		this->value = value;
	}
};

template <typename T>
class HashTable {
	private:
		HashEntry **table;
		int size;
	public:
		HashTable(int size);
		~HashTable();

		int hash(int key);
		int get(int key);
		void set(int key, T value);
		void remove(int key);
};

/*
   Paramaterized Constructor

   @param  size	    size to contruct array
   @return void
*/
template <typename T>
HashTable<T>::HashTable(int size) {
	this->size = size;
	table = new HashEntry* [this->size];
	// constructor array of nullptrs
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

/*
   Destructor
*/
template <typename T>
HashTable<T>::~HashTable() {
	for (int i = 0; i < size; i++) {
		if (table[i] != nullptr) {
		   delete table[i];
		}
	}
	delete[] table;
}

/*
   Returns hash for desired key value

   @param  int	key to be hashed
   @return int	hashed value
*/
template <typename T>
int HashTable<T>::hash(int key) {
	return key % size;
}

/*
   Returns value at desired key

   @param  int	key to be hashed   
   @return T	value at key, if none return 0		
*/
template <typename T>
T HashTable<T>::get(int key) {
	int hashValue = hash(key);
	while (table[hashValue] != nullptr && table[hashValue]->key != key) {
		hashValue = hash(hashValue + 1);
	}

	// if null return
	if (table[hashValue] == nullptr) { return 0; }
	return table[hashValue]->value;
}

/*
   Returns value at desired key

   @param  int	key to be hashed  
   @return void
*/
template <typename T>
void HashTable<T>::set(int key, T value) {
    int hashValue = hash(key);
    while (table[hashValue] != nullptr && table[hashValue]->key != key) {
    	hashValue = hash(hashValue + 1);
    }

    // delete previous and set new
    if (table[hashValue] != nullptr) { delete table[hashValue]; }
    table[hashValue] = new HashEntry(key, value);
}    

/*
   Removes desired key from hashtable

   @param  int	    key to be hashed 
   @return void
*/
template <typename T>
void HashTable<T>::remove(int key) {
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