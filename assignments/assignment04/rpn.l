 /* eliminate the need to link in the fl library */
%option noyywrap

 /* No longer allow default characters to 
    fall through scanner*/
%option nodefault


%{
  /* don't forget to include the bison-generated header file */
  #include<string>
  #include"rpn.tab.h"
  using std::stoi;
%}

%%

[0-9]+  { yylval.myunion_int = stoi(yytext); return T_INT_CONSTANT; }
"+"     { yylval.myunion_char = 'A'; return T_PLUS; }
"-"     { yylval.myunion_char = 'S'; return T_MINUS; }
"*"     { yylval.myunion_char = 'M'; return T_MULTIPLY; }
"/"     { yylval.myunion_char = 'D'; return T_DIVIDE; }
\.      { return T_PRINT; }
\?      { return T_SIZE; }
[ \t\n]      /* do nothing */
.       { return T_ERROR; }

%%
