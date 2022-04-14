// ciscoCoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "LruCache.h"
#include "DataRepositoryFactory.h"

int main()
{
    std::cout << "driver for LruCache" << std::endl;

    DataRepositoryFactory factory;
    IDataRepository* dataRepository = factory.Create(DataRepositoryFactory::MockType);
    std::unique_ptr< IDataRepository> wrap(dataRepository); // a handy man to manange memory for us

    LruCache cache(3, dataRepository);

    DataItem item1(1, "item 1");
    DataItem item2(2, "item 2");
    DataItem item3(3, "item 3");
    DataItem item4(4, "item 4");
    DataItem item5(5, "item 5");

    cache.put(1, item1);
    cache.put(1, item1);
    cache.put(2, item2);
    cache.get(1).print();   // get from cache
    cache.put(3, item3);    // now cache is at capacity of 3
    cache.get(2).print(); // get from cache

    // now lRU list (2, 3, 1)

    cache.put(4, item4); // evict 1
    cache.get(1).print(); // get from db (slow), evict 3
    cache.get(1).setData("item 1 modified"); // get from cache
    cache.get(3).print(); // get from db (slow), evict 2

    // now LRU list (3, 1, 4)

    cache.get(4).print(); // get from cache
    cache.get(3).print(); // get from cache
    cache.put(5, item5); // evit 1, update data for 1

    // now LRU list (5, 3, 4)

    cache.get(1).print();   // get from db (slow)

    
}
