#include <iostream>
#include "LruCache.h"


LruCache::LruCache(int capacity, IDataRepository* repository)
{
	assert(capacity > 0);
	m_capacity = capacity;
	m_repository = repository;
}

LruCache::~LruCache()
{
	// make sure no exception is thrown from the destructor
	try {
		for (auto key_item : m_list) {
			if (key_item.m_item.getDirty()) {
				key_item.m_item.setDirty(false);
				m_repository->update(key_item.m_item); // update item to db 
			}
		}
	}
	catch (...) {
		std::cout << "some data may not have been saved" << std::endl;
	}
}

// get item from cache.  if not existing in cache, try to get from db
DataItem& LruCache::get(int id) 
{
	std::cout << "--------------------- get " << id;
	auto iter = m_hashmap.find(id);
	if (iter == m_hashmap.end()) {
		std::cout << " from db" << std::endl;
		DataItem item = m_repository->get(id);// get item from db

		checkCapacity();

		KeyItem key_item(id, item);
		m_list.push_front(key_item);
		m_hashmap[id] = m_list.begin();
		printList();
		return m_list.front().m_item;
	}

	std::cout << " from cache" << std::endl;
	m_list.splice(m_list.begin(), m_list, iter->second);	// transfer element to the front
	printList();
	return iter->second->m_item;
}

void LruCache::put(int id, const DataItem& item) 
{
	std::cout << "put --------------------- " << id << std::endl;
	auto iter = m_hashmap.find(id);
	if (iter != m_hashmap.end())
	{
		m_list.splice(m_list.begin(), m_list, iter->second);
		iter->second->m_item = item;
		printList();
		return;
	}

	checkCapacity();

	KeyItem new_key_item(id, item);
	m_list.push_front(new_key_item);
	m_hashmap[id] = m_list.begin();
	m_repository->insert(new_key_item.m_item);
	
	printList();
}

void LruCache::checkCapacity()
{
	if (m_hashmap.size() == m_capacity)
	{
		auto key_item = m_list.back();
		int id = key_item.m_key;
		m_list.pop_back();
		m_hashmap.erase(id);
		if (key_item.m_item.getDirty()) {
			key_item.m_item.setDirty(false);
			std::cout << " updating item to db" << std::endl;
			m_repository->update(key_item.m_item); // update item to db on eviction
		}
		std::cout << " evicting " << id << std::endl;
	}
}

void LruCache::printList()const
{
	std::cout << "m_list = (";
	for (auto i : m_list) {
		std::cout << i.m_item.getId() << " ";
	}
	std::cout << ")";
	std::cout << std::endl;
}