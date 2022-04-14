#pragma once
#include <unordered_map>
#include <list>
#include <utility>
#include <cassert>

#include "DataItem.h"
#include "IDataRepository.h"

/*
Implement a local data storage class supplemented by an in-memory LRU cache. The
data storage may use something like sqlite3 for persistence. The LRU cache should be
your own implementation built on data structures/algorithms available in the standard
library for your language/platform. The class should implement the methods `put()` and
`get()`, and provide some way to designate if an object acquired by `get()` has been
mutated by the application. Mutated objects should be written back to persistent
storage on eviction from the LRU.
*/
class LruCache
{
private:
	struct KeyItem {
		KeyItem(int key, const DataItem& item) {
			m_key = key;
			m_item = item;
		}
		int m_key;
		DataItem m_item;
	};

public:
	LruCache(int capacity, IDataRepository* repository);
	~LruCache();
	DataItem& get(int id);
	void put(int id, const DataItem& item);

private:
	void checkCapacity();
	void printList()const;

private:
	IDataRepository* m_repository;

	int m_capacity;
	std::unordered_map<int, std::list<KeyItem>::iterator> m_hashmap;	// first: id, second: m_list iterator (one to one map)
	std::list<KeyItem> m_list;

};

