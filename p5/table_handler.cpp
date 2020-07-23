#include<memory>
#include<string>
#include<iostream>
#include<stdexcept>
#include<vector>

#include "gpl_type.h"
#include "symbol.h"
#include "symbol_table.h"
#include "table_handler.h"

using namespace std;

Table_handler& Table_handler::instance(){
  static Table_handler Table_instance;
  if(Table_instance.tables.empty()){
    Table_instance.push_table();
  }
  return Table_instance;
} 

void Table_handler::push_table(){
  shared_ptr<Symbol_table> symT = make_shared<Symbol_table>();
  tables.push_back(symT);
}

void Table_handler::pop_table(){
  if(tables.size() != 0){
    tables.pop_back();
  }else{
    throw std::underflow_error("Can't pop global symbol table");
  }
}

bool Table_handler::defined_in_current_scope(const string& name){
  return tables[tables.size()-1]->lookup(name)!=nullptr;
}

bool Table_handler::insert(shared_ptr<Symbol> sym){
  return tables[tables.size()-1]->insert(sym);
}

std::shared_ptr<Symbol> Table_handler::lookup(const std:: string& name){
  for(int i = tables.size()-1; i >= 0; --i){
    std::shared_ptr<Symbol> found_symbol=tables[i]->lookup(name);
    if(found_symbol != nullptr){
      return found_symbol;
    }
  }
  return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Table_handler& sh){
  if(sh.tables.size() != 0){
    for(int i = sh.tables.size() -1; i >= 0; i--){
      os << *sh.tables[i]; 
    }
  }
  return os;
}

