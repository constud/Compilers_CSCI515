#ifndef SYMBOL_H
#define SYMBOL_H


#include<memory>
#include<string>
#include <iostream>
#include"gpl_type.h"
#include<unordered_map>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Pixmap.h"
#include "Textbox.h"
#include "Animation_block.h"
using namespace std;


union symbol_type{

	double* double_pointer;
	int* integer_pointer;
	string* string_pointer;
  Rectangle* rectangle_pointer;
  Circle* circle_pointer;
  Textbox* textbox_pointer;
  Triangle* triangle_pointer;
  Pixmap* pixmap_pointer;
  Animation_block* animation_block_pointer;

	symbol_type(double* val) : double_pointer(val){}
	symbol_type(int* val) : integer_pointer(val){}
	symbol_type(string* val) : string_pointer(val){}
  symbol_type(Rectangle* val) : rectangle_pointer(val){}
  symbol_type(Circle* val) : circle_pointer(val){}
  symbol_type(Textbox* val) : textbox_pointer(val){}
  symbol_type(Triangle* val) : triangle_pointer(val){}
  symbol_type(Pixmap* val) : pixmap_pointer(val){}
  symbol_type(Animation_block* val) : animation_block_pointer(val){}
};

class Symbol{


	Symbol(const Symbol&) = delete;
	Symbol& operator=(const Symbol&) = delete;

	public:
		Symbol(const std::string& name, double* value);
		Symbol(const std::string& name, double* value, int count);
		Symbol(const std::string& name, int* value);
		Symbol(const std::string& name, int* value, int count);
		Symbol(const std::string& name, string* value);
		Symbol(const std::string& name, string* value, int count);
    Symbol(const std::string& name, Rectangle* value);
    Symbol(const std::string& name, Rectangle* value, int count);
    Symbol(const std::string& name, Circle* value);
    Symbol(const std::string& name, Circle* value, int count);
    Symbol(const std::string& name, Textbox* value);
    Symbol(const std::string& name, Textbox* value, int count);
    Symbol(const std::string& name, Triangle* value);
    Symbol(const std::string& name, Triangle* value, int count);
    Symbol(const std::string& name, Pixmap* value);
    Symbol(const std::string& name, Pixmap* value, int count);
    Symbol(const std::string& name, Animation_block* value);

		Gpl_type get_type() const;
		std::string get_name() const;
    int get_count() const;
		~Symbol();
    int as_int() const;
    int as_int(int) const;
    double as_double() const;
    double as_double(int) const;
    string as_string() const;
    string as_string(int) const;
    Rectangle* as_rectangle() const;
    Rectangle* as_rectangle(int) const;
    Circle* as_circle() const;
    Circle* as_circle(int) const;
    Textbox* as_textbox() const;
    Textbox* as_textbox(int) const;
    Triangle* as_triangle() const;
    Triangle* as_triangle(int) const;
    Pixmap* as_pixmap() const;
    Pixmap* as_pixmap(int) const;
    Animation_block* as_animation_block() const;
    
    bool is_array();
		friend std::ostream& operator <<(std::ostream& os, const Symbol&);


	private:
    std::string name;
		symbol_type value;
		Gpl_type type;
		int count;

};

#endif
