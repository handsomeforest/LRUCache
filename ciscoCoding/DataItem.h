#pragma once
#include <string>
#include <iostream>

// data model
class DataItem
{
public:
	DataItem(int id = 0, const std::string& data = "") {
		m_id = id;
		m_data = data;
		m_isDirty = false;
	}

	~DataItem() {

	}

	int getId()const {
		return m_id;
	}

	bool getDirty()const {
		return m_isDirty;
	}

	void setDirty(bool dirty) {
		m_isDirty = dirty;
	}

	void setData(const std::string& data) {
		if (m_data != data) {
			m_data = data;
			m_isDirty = true;
		}
	}

	void print()const {
		std::cout << "id = " << m_id << ", data = " << m_data << std::endl;
	}

private:
	bool m_isDirty;
	int m_id;
	std::string m_data;
};