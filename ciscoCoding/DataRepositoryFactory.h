#pragma once
#include "IDataRepository.h"

// factory pattern so we can switch data repository implementation easily
class DataRepositoryFactory
{
public:
	enum {MockType, SqliteType};

	IDataRepository* Create(int type);
	
};

