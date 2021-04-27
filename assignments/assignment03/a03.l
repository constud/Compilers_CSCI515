/* definitions */
%{
    #include<iostream>
    using std::cout;
%}

%option noyywrap


%%
  /* pattern       action */
the|The             { std::cout << " T_DEFINITIVE_ARTICLE"; }
quick|brown|lazy                 { std::cout << " T_ADJECTIVE"; }
fox|dog|wall|liquid|bottles      { std::cout << " T_NOUN";}
jumped|see      { std::cout << " T_VERB"; }
[0-9]           { std::cout << " T_INTEGER";}
over|on|of    { std::cout << " T_PREPOSITION";}
I             { std::cout << " T_PRONOUN";}
[.]           { std::cout << "T_PERIOD";}

%%
int main()
{
  yylex();
  return 0;
}
