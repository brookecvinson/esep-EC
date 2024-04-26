#pragma once
#include <map>
#include <iostream>
#include <string>

class InMemoryDB{
    public:
        InMemoryDB();
        ~InMemoryDB();
        void begin_transaction();
        void put(std::string key, int value);
        int get(std::string key);
        void commit();
        void rollback();
    private:
        std::map<std::string, int> data;
        std::map<std::string, int> transaction;
        bool transactionInProgress;
};