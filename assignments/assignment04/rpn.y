 /* Define your tokens here */
%token <myunion_int> T_INT_CONSTANT;
%token <myunion_char> T_PLUS;
%token <myunion_char> T_MINUS;
%token <myunion_char> T_MULTIPLY;
%token <myunion_char> T_DIVIDE;
%token <myunion_char> T_PRINT;
%token <myunion_char> T_SIZE;
%token <myunion_char> T_ERROR;

%union{ 
    int myunion_int;
    char myunion_char;
}

%{
  /* add all the necessary C++ header files and 
     variables required to manage a stack (hint: see flex_rpn.l
   */
  #include<stack>
  #include<iostream>
  #include<string>
  using std::cout;
  using std::cerr;
  using std::endl;
  using std::stoi;
  using std::string;
  std::stack<int> rpnstack;
  bool stack_error(int expected);
  
  string myGlobalString;




  /* The prototype to yylex() is required since its source is
     in a separate file */
  int yylex();

  /* we must write this function. Generated code calls it */
  void yyerror(const char* err);
%}

%%
arithmetic: input{ cout << "All operations: " << myGlobalString << endl;}
input : /* empty */ 
      | input token
      ; /* semi-colon designates end of "production" */

token: T_INT_CONSTANT {rpnstack.push($1); myGlobalString += std::to_string($1); myGlobalString += ' ';}
    | T_PLUS { if(stack_error(2)) break; 
               myGlobalString += $1; 
               myGlobalString += ' '; 
               int a=rpnstack.top(); 
               rpnstack.pop(); 
               int b=rpnstack.top(); 
               rpnstack.pop(); 
               rpnstack.push(a+b);}
    | T_MINUS { if(stack_error(2)) break;  myGlobalString += $1; myGlobalString += ' '; int a=rpnstack.top(); rpnstack.pop(); int b=rpnstack.top(); rpnstack.pop(); rpnstack.push(a-b);}
    | T_MULTIPLY { if(stack_error(2)) break;  myGlobalString += $1; myGlobalString += ' '; int a=rpnstack.top(); rpnstack.pop(); int b=rpnstack.top(); rpnstack.pop(); rpnstack.push(a*b);}
    | T_DIVIDE { if(stack_error(2)) break;  myGlobalString += $1; myGlobalString += ' '; int a=rpnstack.top(); rpnstack.pop(); int b=rpnstack.top(); rpnstack.pop(); rpnstack.push(a/b);}
    | T_PRINT { if(stack_error(1)) break; cout << rpnstack.top() << endl; rpnstack.pop(); }
    | T_SIZE  { cout << "stack=" << rpnstack.size() << endl; }
    | T_ERROR { cerr << "DOES NOT COMPUTE!" << endl; }

 

; /* semi-colon designates end of "production" */

%%

int main(int argc, char** argv)
{
  yyparse();
}

bool stack_error(int expected)
{
  if(rpnstack.size() < expected)
  {
    cerr << "Stack size to small!\n";
    return 1;
  }
  return 0;
}

void yyerror(const char*err)
{
  cerr << err << endl;
}
