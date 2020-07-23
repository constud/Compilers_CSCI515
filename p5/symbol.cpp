#include "expression.h"
#include<memory>
#include<string>
#include <iostream>
#include "Symbol.h"
#include <vector>
#include<algorithm>
#include <assert.h>
#include "error.h"
#include<iostream>
#include "variable.h"

using namespace std;


Symbol::Symbol(const std::string& name, double* value)  
  : name(name), value(value), type(DOUBLE), count(-1)
{
}
Symbol::Symbol(const std::string& name, double* value, int count)
  : name(name), value(value), type(DOUBLE_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, int* value)
  : name(name), value(value), type(INT), count(-1)
{
}
Symbol::Symbol(const std::string& name, int* value, int count)
  : name(name), value(value), type(INT_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, string* value)
  : name(name), value(value), type(STRING), count(-1)
{
}
Symbol::Symbol(const std::string& name, string* value, int count)
  : name(name), value(value), type(STRING_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, Rectangle* value)
  : name(name), value(value), type(RECTANGLE), count(-1)
{
}
Symbol::Symbol(const std::string& name, Rectangle* value, int count)
  : name(name), value(value), type(RECTANGLE_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, Circle* value)
  : name(name), value(value), type(CIRCLE), count(-1)
{
}
Symbol::Symbol(const std::string& name, Circle* value, int count)
  : name(name), value(value), type(CIRCLE_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, Textbox* value)
  : name(name), value(value), type(TEXTBOX), count(-1)
{
}
Symbol::Symbol(const std::string& name, Textbox* value, int count)
  : name(name), value(value), type(TEXTBOX_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, Triangle* value)
  : name(name), value(value), type(TRIANGLE), count(-1)
{
}
Symbol::Symbol(const std::string& name, Triangle* value, int count)
  : name(name), value(value), type(TRIANGLE_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, Pixmap* value)
  : name(name), value(value), type(PIXMAP), count(-1)
{
}
Symbol::Symbol(const std::string& name, Pixmap* value, int count)
  : name(name), value(value), type(PIXMAP_ARRAY), count(count)
{
}
Symbol::Symbol(const std::string& name, Animation_block* value)
  : name(name), value(value), type(ANIMATION_BLOCK), count(-1)
{
}

ostream& operator<<(std::ostream& os, const Symbol& sym)
{
  if(sym.type==INT || sym.type==DOUBLE || sym.type==STRING || sym.type==RECTANGLE || sym.type==CIRCLE || sym.type==TEXTBOX || sym.type==TRIANGLE || sym.type==PIXMAP || sym.type==ANIMATION_BLOCK){
    os << gpl_type_to_string(sym.type) << ' ' << sym.name; 
    switch(sym.type){
      case INT:
        os <<  " = " << *sym.value.integer_pointer ;
        break;
      case DOUBLE:
        os <<  " = " <<*sym.value.double_pointer ;
        break;
      case STRING:
        os << " = " << "\"" << *sym.value.string_pointer << "\"" ;
        break;
      case RECTANGLE:
        os << *sym.value.rectangle_pointer ;
        break;
      case CIRCLE:
        os << *sym.value.circle_pointer ;
        break;
      case TEXTBOX:
        os << *sym.value.textbox_pointer;
        break;
      case TRIANGLE:
        os << *sym.value.triangle_pointer;
        break;
      case PIXMAP: 
        os << *sym.value.pixmap_pointer;
        break;
      case ANIMATION_BLOCK:
        os << "animation_block " << sym.name;
        break;
      default:
        assert(false);
    }
    cout << '\n';
  }
  if(sym.type==INT_ARRAY || sym.type==DOUBLE_ARRAY || sym.type==STRING_ARRAY || sym.type ==RECTANGLE_ARRAY || sym.type==CIRCLE_ARRAY || sym.type==TEXTBOX_ARRAY || sym.type==TRIANGLE_ARRAY || sym.type==PIXMAP_ARRAY){
    for(int i = 0; i < sym.count; i++){
        switch(sym.type){
            case INT_ARRAY:
                os << "int" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.integer_pointer[i] << endl ;
                break;
            case DOUBLE_ARRAY:
                os << "double" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.double_pointer[i] << endl ;
                break;
            case STRING_ARRAY:
                os << "string" << ' ' << sym.name << '[' << i << ']' << " = " << "\"" << sym.value.string_pointer[i] << "\"" << endl;
                break;
            case RECTANGLE_ARRAY:
                os << "rectangle" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.rectangle_pointer[i] << endl;
                break;
            case CIRCLE_ARRAY:
                os << "circle" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.circle_pointer[i] << endl;
                break;
            case TEXTBOX_ARRAY:
                os << "textbox" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.textbox_pointer[i] << endl;
                break;
            case TRIANGLE_ARRAY:
                os << "triangle" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.triangle_pointer[i] << endl;
                break;
            case PIXMAP_ARRAY:
                os << "pixmap" << ' ' << sym.name << '[' << i << ']' << " = " << sym.value.pixmap_pointer[i] << endl;
                break;
            default:
                assert(false);
        }
    }
  }
    return os;
  }
Symbol::~Symbol()
{
    switch(type)
    {
      case INT:
        delete value.integer_pointer;
        break;
       case DOUBLE:
        delete value.double_pointer;
        break;
       case STRING:
        delete value.string_pointer;
        break;
       case RECTANGLE:
        delete value.rectangle_pointer;
        break;
       case CIRCLE:
        delete value.circle_pointer;
        break;
       case TEXTBOX:
        delete value.textbox_pointer;
        break;
       case TRIANGLE:
        delete value.triangle_pointer;
        break;
       case PIXMAP:
        delete value.pixmap_pointer;
        break;
       case ANIMATION_BLOCK:
        delete value.animation_block_pointer;
        break;
       case INT_ARRAY:
        delete [] value.integer_pointer;
        break;
       case DOUBLE_ARRAY:
        delete [] value.double_pointer;
        break;
       case STRING_ARRAY:
        delete [] value.string_pointer;
        break;
       case RECTANGLE_ARRAY:
        delete [] value.rectangle_pointer;
        break;
       case CIRCLE_ARRAY:
        delete [] value.circle_pointer;
        break;
       case TEXTBOX_ARRAY:
        delete [] value.textbox_pointer;
        break;
       case TRIANGLE_ARRAY:
        delete [] value.triangle_pointer;
        break;
       case PIXMAP_ARRAY:
        delete [] value.pixmap_pointer;
        break;
       default:
        assert(false);
    }
}
Gpl_type Symbol::get_type()const {
    return type;
}
string Symbol::get_name()const {
    return name;
}

int Symbol::get_count()const {
  return count;
}

int Symbol::as_int() const{
  assert(type == INT);
  return *value.integer_pointer;
}

int Symbol::as_int(int index) const{
  assert(type == INT_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return *(value.integer_pointer + index);
}

double Symbol::as_double() const{
  assert(type == DOUBLE);
  return *value.double_pointer;
}

double Symbol::as_double(int index) const{
  assert(type == DOUBLE_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return *(value.double_pointer + index);
}

string Symbol::as_string() const{
  assert(type == STRING);
  return *value.string_pointer;
}

string Symbol::as_string(int index) const{
  assert(type == STRING_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return *(value.string_pointer + index);
}

Rectangle* Symbol::as_rectangle() const{
  assert(type == RECTANGLE);
  return value.rectangle_pointer;
}

Rectangle* Symbol::as_rectangle(int index) const{
  assert(type == RECTANGLE_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return (value.rectangle_pointer + index);
}

Circle* Symbol::as_circle() const{
  assert(type == CIRCLE);
  return value.circle_pointer;
}

Circle* Symbol::as_circle(int index) const{
  assert(type == CIRCLE_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return (value.circle_pointer + index);
}

Textbox* Symbol::as_textbox() const{
  assert(type == TEXTBOX);
  return value.textbox_pointer;
}

Textbox* Symbol::as_textbox(int index) const{
  assert(type == TEXTBOX_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return (value.textbox_pointer + index);
}

Triangle* Symbol::as_triangle() const{
  assert(type == TRIANGLE);
  return value.triangle_pointer;
}

Triangle* Symbol::as_triangle(int index) const{
  assert(type == TRIANGLE_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return (value.triangle_pointer + index);
}

Pixmap* Symbol::as_pixmap() const{
  assert(type == PIXMAP);
  return value.pixmap_pointer;
}

Pixmap* Symbol::as_pixmap(int index) const{
  assert(type == PIXMAP_ARRAY);
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return (value.pixmap_pointer + index);
}

Animation_block* Symbol::as_animation_block() const{
  assert(type == ANIMATION_BLOCK);
  return value.animation_block_pointer;
}


/*int Symbol::index_check(int index){
  if(index < 0 || index > count - 1)
    throw Error::ARRAY_INDEX_OUT_OF_BOUNDS;
  return index;
}*/

bool Symbol::is_array() {
  if(type == INT_ARRAY || type == DOUBLE_ARRAY || type == STRING_ARRAY)
    return true;
  return false;
}
