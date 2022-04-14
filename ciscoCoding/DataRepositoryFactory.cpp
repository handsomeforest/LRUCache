#include "DataRepositoryFactory.h"
#include "MockDataRepository.h"
#include "SqliteDataRepository.h"


IDataRepository* DataRepositoryFactory::Create(int type)
{
	if (type == MockType) {
		return new MockDataRepository();
	}
	else if (type == SqliteType) {
		return new SqliteDataRepository();
	}
	else {
		throw std::exception("invalid data repo type");
	}
}