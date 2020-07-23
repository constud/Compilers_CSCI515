#include "gpl_type.h"
#include "Variable.h"
#include "Expression.h"
#include "constant.h"
#include "limits.h"
#include "symbol.h"
#include "error.h"
#include <cassert>

 
Gpl_type Variable::type() const{
  return symbol->get_type();
}

Constant* Variable::evaluate(){
  delete evaluated_constant;
  if(array_index_expression == nullptr){
    switch(symbol -> get_type()){
        case INT:
          return evaluated_constant = new Integer_constant(symbol->as_int());
          break;
        case DOUBLE:
          return evaluated_constant = new Double_constant(symbol->as_double());
          break;
        case STRING:
          return evaluated_constant = new String_constant(symbol->as_string());
          break;
        case RECTANGLE:
          return evaluated_constant = new Rectangle_constant(symbol->as_rectangle());
          break;
        case CIRCLE:
          return evaluated_constant = new Circle_constant(symbol->as_circle());
          break;
        case TEXTBOX:
          return evaluated_constant = new Textbox_constant(symbol->as_textbox());
          break;
        case TRIANGLE:
          return evaluated_constant = new Triangle_constant(symbol->as_triangle());
          break;
        case PIXMAP:
          return evaluated_constant = new Pixmap_constant(symbol->as_pixmap());
          break;
        case ANIMATION_BLOCK:
          return evaluated_constant = new Animation_block_constant(symbol->as_animation_block());
          break;
        default:
          return evaluated_constant = new Integer_constant(0);
    }
  }
  if(array_index_expression -> type() != INT){
    Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER, symbol -> get_name(), to_string(array_index_expression->evaluate()->as_int()));
    return evaluated_constant = new Integer_constant(0);
  }
  int index_constant = array_index_expression->evaluate()->as_int();
  if(index_constant < 0 || index_constant > symbol -> get_count()-1){
      Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS, symbol->get_name(), std::to_string(index_constant));
      index_constant = 1;
    }
  switch(symbol->get_type()){
    case INT_ARRAY:
      return evaluated_constant = new Integer_constant(symbol->as_int(index_constant));
    case DOUBLE_ARRAY:
      return evaluated_constant = new Double_constant(symbol->as_double(index_constant));
    case STRING_ARRAY:
      return evaluated_constant = new String_constant(symbol->as_string(index_constant));
    case RECTANGLE_ARRAY: 
      return evaluated_constant = new Rectangle_constant(symbol->as_rectangle(index_constant));
    case CIRCLE_ARRAY: 
      return evaluated_constant = new Circle_constant(symbol->as_circle(index_constant));
    case TEXTBOX_ARRAY: 
      return evaluated_constant = new Textbox_constant(symbol->as_textbox(index_constant));
    case TRIANGLE_ARRAY: 
      return evaluated_constant = new Triangle_constant(symbol->as_triangle(index_constant));
    case PIXMAP_ARRAY: 
      return evaluated_constant = new Pixmap_constant(symbol->as_pixmap(index_constant));
    default:
      assert(false);
  }
  return nullptr;
}
    

Variable::Variable(shared_ptr<Symbol> sym)
  : symbol(sym), array_index_expression(nullptr)
{
}

Variable::Variable(shared_ptr<Symbol> sym, Expression* arridx)
  : symbol(sym), array_index_expression(arridx)
{
}

Variable::~Variable()
{
  delete array_index_expression;
}

Gpl_type Member_variable::type() const
{
  Game_object* game_object_ptr = nullptr;
  switch(symbol->get_type())
  {
    case RECTANGLE:
      return Rectangle::get_member_variable_type(data_member_name);
      break;
    case TRIANGLE:
      return Triangle::get_member_variable_type(data_member_name);
      break;
    case CIRCLE:
      return Circle::get_member_variable_type(data_member_name);
      break;
    case TEXTBOX:
      return Textbox::get_member_variable_type(data_member_name);
      break;
    case PIXMAP:
      return Pixmap::get_member_variable_type(data_member_name);
      break;
    default:
      cerr << "No valid type=" << symbol->get_type() << '\n';
      assert(false);
   }
}

Constant* Member_variable::evaluate(){
  Game_object* game_object_ptr = nullptr;
   switch(symbol->get_type()){
    case RECTANGLE:
      {
        Rectangle* game_object_ptr = symbol->as_rectangle();
        break;
      }
    case TRIANGLE:
      {
        Triangle* game_object_ptr = symbol -> as_triangle();
        break;
      }
    case  CIRCLE:
      {
        Circle* game_object_ptr = symbol -> as_circle();
        break;
      }
    case TEXTBOX:
      {
        Textbox* game_object_ptr = symbol -> as_textbox();
      }
    case PIXMAP:
      {
        Pixmap* game_object_ptr = symbol -> as_pixmap();
      }
    default:
      assert(false);
   }
   switch(this->type()){
     case INT:
       {
         int val;
         game_object_ptr->get_member_variable(data_member_name, val);
         return new Integer_constant(val);
       }
     case DOUBLE:
       {
         double val;
         game_object_ptr->get_member_variable(data_member_name, val);
         return new Double_constant(val);
       }
     case STRING:
       {
         string val;
         game_object_ptr->get_member_variable(data_member_name, val);
         return new String_constant(val);
       }
     default:
       assert(false);
   }
}


Member_variable::Member_variable(std::shared_ptr<Symbol> sym, const std::string& dmn)
  : Variable(sym), data_member_name(dmn)
{
}

Member_variable::Member_variable(std::shared_ptr<Symbol> sym, Expression* index_exp, const std::string& dmn)
  : Variable(sym, index_exp), data_member_name(dmn)
{
}

