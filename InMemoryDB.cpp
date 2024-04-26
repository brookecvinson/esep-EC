#include "InMemoryDB.h"

InMemoryDB::InMemoryDB(){
    transactionInProgress = false;
}
InMemoryDB::~InMemoryDB(){
    transaction.clear();
    data.clear();
}
void InMemoryDB::begin_transaction(){
    transactionInProgress = true;
}
void InMemoryDB::put(std::string key, int value){
    try{
        if(!transactionInProgress){
            throw std::invalid_argument("Error: No transaction in progress.");
        }
        transaction[key] = value;
    }
    catch(const std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }
    
}
int InMemoryDB::get(std::string key){
    //no null option for a c++ int. if the key is not found, 0 is returned
    return data[key];
}
void InMemoryDB::commit(){
    std::map<std::string, int>::iterator it;
    for(it = transaction.begin(); it != transaction.end(); it ++){
        data[it->first] = it->second;
    }
}
void InMemoryDB::rollback(){
    transaction.clear();
    transactionInProgress = false;
}