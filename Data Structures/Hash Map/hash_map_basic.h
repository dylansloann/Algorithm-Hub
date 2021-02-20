#ifndef HASH_TABLE_BASIC_H
#define HASH_TABLE_BASIC_H

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
class BasicHashMap {
	private:
		HashEntry<T>** map;
		int size;
	public:
		BasicHashMap(int size);
		~BasicHashMap();

		int hash(int key);
		T get(int key);
		void set(int key, T value);
		void remove(int key);
};

/*
   Paramaterized Constructor

   @param  size	    size to contruct array
   @return void
*/
template <typename T>
BasicHashMap<T>::BasicHashMap(int size) : size(size), map(new HashEntry<T>* [this->size]()) {}

/*
   Destructor
*/
template <typename T>
BasicHashMap<T>::~BasicHashMap() {
	// deallocates all pointers on hash map
	for (int i = 0; i < size; i++) {
		if (map[i] != nullptr)
		   delete map[i];
	}
	
	delete[] map;
}

/*
   Returns hash for desired key value

   @param  int	key to be hashed
   @return int	hashed value
*/
template <typename T>
int BasicHashMap<T>::hash(int key) {
	return key % size;
}

/*
   Returns value at desired key

   @param  int	key to be hashed   
   @return T	value at key, if none return 0		
*/
template <typename T>
T BasicHashMap<T>::get(int key) {
	int hashValue = hash(key);
	while (map[hashValue] != nullptr) {
		if (map[hashValue]->key == key) 
			return map[hashValue]->value;
		else hashValue = hash(hashValue + 1);
	}

	// if nullptr return null element according to type
	return NULL;
}

/*
   Returns value at desired key

   @param  int	key to be hashed  
   @return void
*/
template <typename T>
void BasicHashMap<T>::set(int key, T value) {
    int hashValue = hash(key);
    while (map[hashValue] != nullptr) {
    	if (map[hashValue]->key != key)
			hashValue = hash(hashValue + 1);
		else break;
    }

    // delete old key and set new
    if (map[hashValue] != nullptr) 
		delete map[hashValue];
    map[hashValue] = new HashEntry<T>(key, value);
}    

/*
   Removes desired key from hashtable

   @param  int	    key to be hashed 
   @return void
*/
template <typename T>
void BasicHashMap<T>::remove(int key) {
	int hashValue = hash(key);
	while (map[hashValue] != nullptr) {
		if (map[hashValue]->key == key) {
			delete map[hashValue]; 
			return;
		}
		else hashValue = hash(hashValue + 1);
	}
}

#endif