#include "InMemoryDB.h"
int main(){
    InMemoryDB db = InMemoryDB();

    std::cout << "Value of \"A\": " << db.get("A") << std::endl;

    std::cout << std::endl << "Attempting to put an entry when no transaction has been initiated." << std::endl;
    db.put("A", 1);

    db.begin_transaction();
    db.put("A", 1);
    std::cout << std::endl << "Adding \"A\" to transaction and commited." << std::endl;

    std::cout << "Value of \"A\": " << db.get("A") << std::endl;

    std::cout << "\nAdding \"B\" but not commiting.\n";
    db.put("B", 2);
    std::cout << "Value of \"B\": " << db.get("B") << std::endl;

    std::cout << "\nRollback and attempting to put an element in the database.\n";
    db.rollback();
    db.put("C", 3); 

    return 0;
}