// Scanner.h

#include <stdbool.h>

#ifndef SCANNER_H
#define SCANNER_H

#define MAXLEXEME   10

enum TokenType {
    Number,
    Addition='+',
    Multiplication='*',
    Substraction='-',
    Division='/',
    PopResult='\n',
    LexError
};

typedef enum TokenType TokenType;
typedef double TokenValue;

struct Token {
    TokenType type;
    TokenValue value;
    char lexeme[MAXLEXEME];
};

bool GetNextToken(struct Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido.

#endif