// Scanner.c

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Scanner.h"

bool GetNextToken(struct Token *t)
{
    char c;
    while((t->lexeme[0] = c = getchar()) == ' ' || c == '\t')
        ;
    
    //no más caracteres para leer
    if(c == EOF)
        return false;
    
    if(!isdigit(c) && c != '.')
    {
        //token no numérico
        t->type = c;
        t->lexeme[1] = '\0';

        return true;
    }

    int i = 0;
    if(isdigit(c))
        while(i < MAXLEXEME && isdigit(t->lexeme[++i] = c = getchar()))
            ;
    
    if(c == '.')
        while(i < MAXLEXEME && isdigit(t->lexeme[++i] = c = getchar()))
            ;
    
    t->lexeme[i] = '\0';

    t->type = Number;
    t->value = atof(t->lexeme);

    //devolver último caracter leído al flujo,
    //para ser obtenido en la próxima iteración
    ungetc(c, stdin);

    return true;
}