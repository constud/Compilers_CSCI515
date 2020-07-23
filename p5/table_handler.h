#ifndef TABLE_HANDLER
#define TABLE_HANDLER
#include<iostream>
#include<memory>
#include<vector>
#include "symbol.h"
#include "symbol_table.h"

class Table_handler{
  public:
    static Table_handler& instance();
    friend std::ostream& operator<<(std::ostream& os, const Table_handler& sh); 
    void push_table();
    void pop_table();
    bool insert(std::shared_ptr<Symbol> sym);
    std::shared_ptr<Symbol> lookup(const std::string& name);
    bool defined_in_current_scope(const std::string& name);
  private:
    std::vector<std::shared_ptr<Symbol_table>> tables;
    Table_handler(){push_table();}
};

#endif
