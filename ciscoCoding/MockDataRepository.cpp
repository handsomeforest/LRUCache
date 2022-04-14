#include <string>
#include <iostream>
#include "MockDataRepository.h"

std::unordered_map<int, DataItem> MockDataRepository::m_db;

MockDataRepository::MockDataRepository()
{
	std::cout << "MockDataRepository()" << std::endl;
}

MockDataRepository::~MockDataRepository()
{
	std::cout << "~MockDataRepository()" << std::endl;
}

void MockDataRepository::insert(const DataItem& item)
{
	int id = item.getId();
	if (m_db.contains(id)) {
		std::string msg = std::string("id ") + std::to_string(id) + " already exists in database";
		throw std::exception(msg.c_str());
	}

	m_db[id] = item;
}

void MockDataRepository::update(const DataItem& item)
{
	int id = item.getId();
	if (!m_db.contains(id)) {
		std::string msg = std::string("id ") + std::to_string(id) + " not found in database";
		throw std::exception(msg.c_str());
	}

	m_db[id] = item;
}

DataItem MockDataRepository::get(int id)const
{
	if (m_db.contains(id)) {
		return m_db[id];
	}

	std::string msg = std::string("id ") + std::to_string(id) + " not found in database";
	throw std::exception(msg.c_str());

}

