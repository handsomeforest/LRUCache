#pragma once
#include "DataItem.h"

// data repository interface
class IDataRepository
{
public:
	virtual ~IDataRepository() {}
	virtual void insert(const DataItem& item) = 0;
	virtual void update(const DataItem& item) = 0;
	virtual DataItem get(int id)const = 0;

};