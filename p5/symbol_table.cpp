#include<iostream>
#include<memory>
#include<bits/stdc++.h>
#include "symbol_table.h"
#include "symbol.h"
#include "gpl_assert.h"


using namespace std;
using std::shared_ptr;

std::shared_ptr<Symbol> Symbol_table::lookup(const std::string& name){
  auto it = symbols.find(name);
  if(it != symbols.end())
    return it->second;
  else
    return nullptr;
}

bool Symbol_table::insert(std::shared_ptr<Symbol> sym){
 if(symbols.find(sym->get_name()) == symbols.end()){
   symbols[sym->get_name()] = sym;
   return true;
   }
 else{
    return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Symbol_table& sym){
  std::vector<string> keys;
  for(auto i = sym.symbols.begin(); i != sym.symbols.end(); i++){
    keys.push_back(i->first);
  }
  std::sort(keys.begin(), keys.end());
  for(unsigned int i = 0; i < keys.size(); i++){
    os << *(sym.symbols.at(keys[i]));
  }
  return os;
}
