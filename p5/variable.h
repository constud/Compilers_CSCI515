#ifndef VARIABLE_H
#define VARIABLE_H
#include "Expression.h"
#include "parser.h"
#include<cassert>

class Variable : public Expression {
  public:
    Variable(std::shared_ptr<Symbol> sym);
    Variable(std::shared_ptr<Symbol> sym, Expression* array_index_expression);
    virtual Constant* evaluate();
    virtual Gpl_type type() const;
    Variable(const Variable&) = delete;
    Variable& operator=(const Variable&) = delete;
    virtual ~Variable();
  protected:
    std::shared_ptr<Symbol> symbol;
    Expression* array_index_expression;
};

class Member_variable : public Variable{
  public:
    Member_variable(std::shared_ptr<Symbol> sym, const std::string& dmn);
    Member_variable(std::shared_ptr<Symbol> sym, Expression* index_exp, const std::string& dmn);
    virtual Constant* evaluate();
    virtual Gpl_type type() const;
  private:
    std::string data_member_name;
};
#endif
