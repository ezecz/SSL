// Calculator.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Scanner.h"
#include "StackOfDoublesModule.h"

//TODO: en lugar de salir con error se podría
//vaciar la pila y seguir operando normalmente
void PolCalcError(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    char error[100];
    vsnprintf(error, (size_t) 100, format, args);

    va_end(args);

    printf("error: %s\n", error);

    exit(EXIT_FAILURE);
}

int IsTokenOperator(struct Token token)
{
    TokenType type = token.type;

    return (type == Addition || type == Multiplication
        || type == Substraction || type == Division);
}

int main(void)
{
    struct Token token;
    while(GetNextToken(&token))
    {
        if(IsTokenOperator(token))
        {
            //detección de errores de sintaxis:
            //error si se encuentra un operador teniendo
            //menos operandos en la pila de los necesarios
            if(StackLevel() < 2)
                PolCalcError("sintaxis incorrecta (operador %s)", token.lexeme);
        }

        StackItem op2;
        switch(token.type)
        {
            case Number:
                Push(token.value);
                break;
            
            case Addition:
                Push(Pop() + Pop());
                break;
            
            case Multiplication:
                Push(Pop() * Pop());
                break;
            
            case Substraction:
                op2 = Pop();
                Push(Pop() - op2);
                break;
            
            case Division:
                op2 = Pop();
                if(op2 != 0.0)
                    Push(Pop() / op2);
                else
                    PolCalcError("divisor cero");
                break;
            
            case PopResult:
                if(StackLevel() > 0)
                {
                    //debe quedar un solo número en la pila para arrojar 
                    //un resultado válido, e.g. error si se ingresa "1 2\n"
                    if(StackLevel() > 1)
                        PolCalcError("se ingresó %d elemento/s de más", StackLevel() - 1);
                    
                    printf("resultado: %.8g\n", Pop());
                }
                
                break;
            
            default:
                printf("error: '%s' no es token\n", token.lexeme);
        }
    }

    return 0;
}