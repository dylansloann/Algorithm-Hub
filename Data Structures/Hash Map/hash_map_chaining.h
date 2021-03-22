#ifndef HASH_MAP_CHAINING_H
#define HASH_MAP_CHAINING_H

#include <vector>
#include <iostream>

template <typename T, typename V>
struct HashEntry {
	T key;
	V value;
	HashEntry(T key, V value) : key(key), value{value} {}
};

template <typename T, typename V>
class ChainHashMap {
    private:
        int size;
        std::vector<std::vector<HashEntry<T,V>>> map;
    public:
        ChainHashMap(int size);
        ~ChainHashMap();
        
        int hash(T key);
        V get(T key);
        void set(T key, V data);
        void remove(T key);

        void clear();
};

/*
   Paramaterized Constructor

   @param  size	    size to contruct array
   @return void
*/
template <typename T, typename V>
ChainHashMap<T,V>::ChainHashMap(int size) : size(size) {
    map.resize(size);
}

/*
   Destructor
*/
template <typename T, typename V>
ChainHashMap<T,V>::~ChainHashMap() { clear(); }

/*
   Returns hash for desired key value

   @param  int	key to be hashed
   @return int	hashed value
*/
template <typename T, typename V>
int ChainHashMap<T,V>::hash(T key) {
    // only works for integers or double keys
    return 2;
}

/*
   Returns value at desired key

   @param  int	key to be hashed   
   @return T	value at key, if none return 0		
*/
template <typename T, typename V>
V ChainHashMap<T,V>::get(T key) {
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
template <typename T, typename V>
void ChainHashMap<T,V>::set(T key, V data) {
    int index = hash(key);
    HashEntry<T,V>* newEntry = new HashEntry<T,V>(key, data);
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
template <typename T, typename V>
void ChainHashMap<T,V>::remove(T key) {
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

/*
   Deallocates all pointers in hash map array

   @param  none
   @return void
*/
template <typename T, typename V>
void ChainHashMap<T,V>::clear() {
	delete[] map;
}

#endif