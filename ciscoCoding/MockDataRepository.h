#pragma once
#include <unordered_map>
#include "IDataRepository.h"

// mock data repository for testing
class MockDataRepository :
    public IDataRepository
{
public:
	MockDataRepository();
	virtual ~MockDataRepository();
	virtual void insert(const DataItem& item)override;
	virtual void update(const DataItem& item)override;
	virtual DataItem get(int id)const override;

private:
	static std::unordered_map<int, DataItem> m_db;
};

