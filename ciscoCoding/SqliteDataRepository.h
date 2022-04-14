#pragma once
#include "IDataRepository.h"

// sqlite data repository
// due to time constraint, i am not implementing this class
class SqliteDataRepository :
    public IDataRepository
{
public:
	SqliteDataRepository();
	virtual ~SqliteDataRepository();
	virtual void insert(const DataItem& item) override;
	virtual void update(const DataItem& item) override;
	virtual DataItem get(int id)const override;
};

