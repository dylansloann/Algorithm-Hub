#ifndef HASH_MAP_CHAINING_H
#define HASH_MAP_CHAINING_H

#include <vector>
#include <iostream>

template <typename T>
struct HashEntry {
	int key;
	T value;
	HashEntry(int key, T value) {
		this->key= key;
		this->value = value;
	}
};

template <typename T>
class ChainHashMap {
    private:
        int size;
        std::vector<HashEntry<T>>* map;
    public:
        ChainHashMap(int size);
        ~ChainHashMap();
        
        int hash(int key);
        T get(int key);
        void set(int key, T data);
        void remove(int key);
};

/*
   Paramaterized Constructor

   @param  size	    size to contruct array
   @return void
*/
template <typename T>
ChainHashMap<T>::ChainHashMap(int size) : size(size), map(new std::vector<HashEntry<T>>[size]) {}

/*
   Destructor
*/
template <typename T>
ChainHashMap<T>::~ChainHashMap() {	delete[] map; }

/*
   Returns hash for desired key value

   @param  int	key to be hashed
   @return int	hashed value
*/
template <typename T>
int ChainHashMap<T>::hash(int key) {
    return key % size;
}

/*
   Returns value at desired key

   @param  int	key to be hashed   
   @return T	value at key, if none return 0		
*/
template <typename T>
T ChainHashMap<T>::get(int key) {
    int index = hash(key);
    for (int i = 0; i < map[index].size(); i++) {
        if (map[index][i].key == key) {
            return map[index][i].value;
        }
    }

    return NULL;
}

/*
   Returns value at desired key

   @param  int	key to be hashed  
   @return void
*/
template <typename T>
void ChainHashMap<T>::set(int key, T data) {
    int index = hash(key);
    HashEntry<T>* newEntry = new HashEntry<T>(key, data);
    for (int i = 0; i < map[index].size(); i++) {
        if (map[index][i].key == key) {
            map[index][i].value = newEntry->value;
            return;
        }
    }
    map[index].push_back(*newEntry);
    delete newEntry;
}

/*
   Removes desired key from hashtable

   @param  int	    key to be hashed 
   @return void
*/
template <typename T>
void ChainHashMap<T>::remove(int key) {
    int index = hash(key);
       
    int vecIndex = 0;
    bool found = false;
    for (int i = 0; i < map[index].size(); i++) {
        if (map[index][i].key == key) {
            vecIndex = i;
            found = true;
            break;
        }
    }

    if (found) {
        map[index].erase(map[index].begin() + vecIndex);
    }
}

#endif