%option noyywrap
%{
    #include <stdlib.h>
    #include "Scanner.h"
%}

NUMBER          [0-9]+(\.)?[0-9]*|\.[0-9]+
ADDITION        \+
MULTIPLICATION  \*
SUBSTRACTION    \-
DIVISION        \/
POPRESULT       \n
SPACE           [\t\ ]+

%%

{NUMBER}            return Number;
{ADDITION}          return Addition;
{MULTIPLICATION}    return Multiplication;
{SUBSTRACTION}      return Substraction;
{DIVISION}          return Division;
{POPRESULT}         return PopResult;
{SPACE}             ;
.                   return LexError;

%%

bool GetNextToken(struct Token *t)
{
    TokenType type = yylex();

    //no hay más caracteres para leer
    if(*yytext == '\0')
        return false;
    
    if((t->type = type) == Number)
        t->value = atof(yytext);
    
    strncpy(t->lexeme, yytext, MAXLEXEME);

    return true;
}