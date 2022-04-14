#include "SqliteDataRepository.h"

SqliteDataRepository::SqliteDataRepository()
{
	std::cout << "SqliteDataRepository()" << std::endl;
}

SqliteDataRepository::~SqliteDataRepository()
{
	std::cout << "~SqliteDataRepository()" << std::endl;
}

void SqliteDataRepository::insert(const DataItem& item)
{
	throw std::exception("SqliteDataRepository::insert not implemented");
}

void SqliteDataRepository::update(const DataItem& item)
{
	throw std::exception("SqliteDataRepository::update not implemented");
}

DataItem SqliteDataRepository::get(int id)const
{
	throw std::exception("SqliteDataRepository::get not implemented");
}

