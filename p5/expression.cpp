// File: Expression.cpp
#include "gpl_type.h"
#include "error.h"
#include "Expression.h"
#include "Constant.h"
#include "Variable.h"
#include "limits.h"
#include<string>
#include <cmath>
#include <time.h>
using std::string;

/**********************************************/
/************* Other operators ****************/
/**********************************************/

Constant* Unary_operator::ret(Constant* cp)
{
  delete evaluated_constant;
  return evaluated_constant = cp;
}

Expression::~Expression(){delete evaluated_constant;}

Gpl_type Or::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Or::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() || rhs_constant->as_int());
  }catch(...){ 
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() || rhs_constant->as_double());
  }
}

Gpl_type And::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht!=DOUBLE || rht!=DOUBLE)
    return INT;
  return DOUBLE;
}

Constant* And::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() && rhs_constant->as_int());
  }catch(...){ 
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() && rhs_constant->as_double());
  }
}


Gpl_type Less_Equal::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Less_Equal::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() <= rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() <= rhs_constant->as_double());
  }catch(...){
    return evaluated_constant = new Integer_constant(lhs_constant->as_string() <= rhs_constant->as_string());
  }
  }
}

Gpl_type Greater_Equal::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Greater_Equal::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() >= rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() >= rhs_constant->as_double());
  }catch(...){
    return evaluated_constant = new Integer_constant(lhs_constant->as_string() >= rhs_constant->as_string());
  }
  } 
}

Gpl_type Greater_Than::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Greater_Than::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() > rhs_constant->as_int());
  }catch(...){try{ 
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() > rhs_constant->as_double());
  }catch(...){
    return evaluated_constant = new Integer_constant(lhs_constant->as_string() > rhs_constant->as_string());
  }
  }
}

Gpl_type Less_Than::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return INT;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Less_Than::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() < rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() < rhs_constant->as_double());
  }catch(...){  
    return evaluated_constant = new Integer_constant(lhs_constant->as_string() < rhs_constant->as_string());
  }
  }
}

Gpl_type Not_Equal::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return INT;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Not_Equal::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() != rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() != rhs_constant->as_double());
  }catch(...){  
    return evaluated_constant = new Integer_constant(lhs_constant->as_string() != rhs_constant->as_string());
  }
  }
}

Gpl_type Equal::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return INT;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Equal::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() == rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_double() == rhs_constant->as_double());
  }catch(...){  
    return evaluated_constant = new Integer_constant(lhs_constant->as_string() == rhs_constant->as_string());
  }
  }
}


Gpl_type Plus::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Plus::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() + rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Double_constant(lhs_constant->as_double() + rhs_constant->as_double());
  }catch(...){  
    return evaluated_constant = new String_constant(lhs_constant->as_string() + rhs_constant->as_string());
  }
  }
}

Gpl_type Minus::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return INT;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Minus::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() - rhs_constant->as_int());
  }catch(...){ 
    return evaluated_constant = new Double_constant(lhs_constant->as_double() - rhs_constant->as_double());
  }
}

Gpl_type Multiply::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return INT;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Multiply::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant=lhs->evaluate();
  Constant* rhs_constant=rhs->evaluate();
  try {
    return evaluated_constant=new Integer_constant(lhs_constant->as_int() * rhs_constant->as_int());
  }catch(...) {
    return evaluated_constant=new Double_constant(lhs_constant->as_double() * rhs_constant->as_double());
  }
}

Gpl_type Divide::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return INT;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Divide::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant=lhs->evaluate();
  Constant* rhs_constant=rhs->evaluate();
  try {
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() / rhs_constant->as_int());
  }catch(...) {
    return evaluated_constant = new Double_constant(lhs_constant->as_double() / rhs_constant->as_double());
  }
}

Gpl_type Mod::type() const
{
  //Gpl_type lht=lhs->type();
  //Gpl_type rht=rhs->type();
  return INT;
}

Constant* Mod::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant=lhs->evaluate();
  Constant* rhs_constant=rhs->evaluate();
  return evaluated_constant=new Integer_constant(lhs_constant->as_int() % rhs_constant->as_int());
}

Gpl_type Not::type() const
{
  Gpl_type lht=lhs->type();
  if(lht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Not::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(!lhs_constant->as_int());
  }catch(...){ 
    return evaluated_constant = new Integer_constant(!lhs_constant->as_double());
  }
}

Gpl_type Unary_Minus::type() const
{
  Gpl_type lht=lhs->type();
  if(lht==STRING)
    return STRING;
  if(lht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Unary_Minus::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(-lhs_constant->as_int());
  }catch(...){ 
    return evaluated_constant = new Double_constant(-lhs_constant->as_double());
  }
}

Gpl_type Sin::type() const
{
  //Gpl_type lht=lhs->type();
  return DOUBLE;
}

Constant* Sin::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Double_constant(sin(lhs_constant->as_int()*M_PI/180));
    }catch(...) {
    return evaluated_constant = new Double_constant(sin(lhs->evaluate()->as_double()*M_PI/180));
  }
}

Gpl_type Cos::type() const
{
  //Gpl_type lht=lhs->type();
  return DOUBLE;
}

Constant* Cos::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Double_constant(cos(lhs_constant->as_int()*M_PI/180));
    }catch(...) {
    return evaluated_constant = new Double_constant(cos(lhs->evaluate()->as_double()*M_PI/180));
  }
}

Gpl_type Tan::type() const
{
  //Gpl_type lht=lhs->type();
    return DOUBLE;
}

Constant* Tan::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Double_constant(tan(lhs_constant->as_int()*M_PI/180));
    }catch(...) {
    return evaluated_constant = new Double_constant(tan(lhs->evaluate()->as_double()*M_PI/180));
  }

}

Gpl_type Acos::type() const
{
  //Gpl_type lht=lhs->type();
    return DOUBLE;
}

Constant* Acos::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Double_constant(acos(lhs_constant->as_int())*180/M_PI);
    }catch(...) {
    return evaluated_constant = new Double_constant(acos(lhs->evaluate()->as_double())*180/M_PI);
  }
}

Gpl_type Asin::type() const
{
  //Gpl_type lht=lhs->type();
    return DOUBLE;
}

Constant* Asin::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Double_constant(asin(lhs_constant->as_int())*180/M_PI);
    }catch(...) {
    return evaluated_constant = new Double_constant(asin(lhs->evaluate()->as_double())*180/M_PI);
  }

}

Gpl_type Atan::type() const
{
  //Gpl_type lht=lhs->type();
    return DOUBLE;
}

Constant* Atan::evaluate()
{
  delete evaluated_constant;
  Constant* lhs_constant = lhs->evaluate();
  try{
    return evaluated_constant = new Double_constant(atan(lhs_constant->as_int())*180/M_PI);
    }catch(...) {
    return evaluated_constant = new Double_constant(atan(lhs->evaluate()->as_double())*180/M_PI);
  }
}

Gpl_type Abs::type() const {
  Gpl_type lht = lhs->type();
  if (lht == DOUBLE) {
    return DOUBLE;
  } else {
    return INT;
  }
}
Constant* Abs::evaluate() {
  delete evaluated_constant;
  try {
    return ret(new Integer_constant(abs(lhs->evaluate()->as_int())));
  } catch(...) {
    return ret(new Double_constant(abs(lhs->evaluate()->as_double())));
  }
}

Gpl_type Sqrt::type() const {
        Gpl_type lht = lhs->type();
        if(lht==STRING)
                return INT;
        if(lht==DOUBLE)
                return DOUBLE;
        return INT;
}

Constant* Sqrt::evaluate(){
        delete evaluated_constant;
        Constant* lhs_constant=lhs->evaluate();
        return evaluated_constant = new Double_constant(sqrt(lhs_constant->as_double()));
}

Gpl_type Floor::type() const {
        Gpl_type lht = lhs->type();
        if(lht==DOUBLE)
                return DOUBLE;
        return INT;
}

Constant* Floor::evaluate(){
        delete evaluated_constant;
        Constant* lhs_constant=lhs->evaluate();
          try {
                return evaluated_constant = new Integer_constant(floor(lhs_constant->as_int()));
        } catch(...) {
                return evaluated_constant = new Integer_constant(floor(lhs_constant->as_double()));
  }
}

Gpl_type Random::type() const
{
  Gpl_type lht=lhs->type();
  if(lht==DOUBLE)
    return DOUBLE;
  return INT;
}


Constant* Random::evaluate()
{
  delete evaluated_constant;
  Constant* result=lhs->evaluate();
  int randbound=-1;
  try {
    randbound=result->as_int();
    if(randbound<1)
      Error::error(Error::INVALID_ARGUMENT_FOR_RANDOM, std::to_string(randbound));
  }
  catch(...)
  {
    double dblnum=result->as_double();
    randbound=static_cast<int>(std::floor(dblnum));
    if(randbound<1)
      Error::error(Error::INVALID_ARGUMENT_FOR_RANDOM, std::to_string(dblnum));
  }
  randbound=(randbound<1) ? 2 : randbound;
  return ret(new Integer_constant(std::rand()%randbound));
}


/*
Gpl_type Near::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Near::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() near rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Double_constant(lhs_constant->as_double() near rhs_constant->as_double());
  }catch(...){ 
    return evaluated_constant = new String_constant(lhs_constant->as_string() near rhs_constant->as_string());
  }
  }
}

Gpl_type Touches::type() const
{
  Gpl_type lht=lhs->type();
  Gpl_type rht=rhs->type();
  if(lht==STRING || rht==STRING)
    return STRING;
  if(lht==DOUBLE || rht==DOUBLE)
    return DOUBLE;
  return INT;
}

Constant* Touches::evaluate()
{
  Constant* lhs_constant = lhs->evaluate();
  Constant* rhs_constant = rhs->evaluate();
  try{
    return evaluated_constant = new Integer_constant(lhs_constant->as_int() touches rhs_constant->as_int());
  }catch(...){ try{
    return evaluated_constant = new Double_constant(lhs_constant->as_double() touches rhs_constant->as_double());
  }catch(...){ 
    return evaluated_constant = new String_constant(lhs_constant->as_string() touches rhs_constant->as_string());
  }
  }
}*/
