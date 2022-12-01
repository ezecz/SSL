// StackOfDoublesModule.c

#include "StackOfDoublesModule.h"

#define MAXITEM 10

//Implementación contigua de la pila usando subindicación.
int theLevel = 0;
StackItem theElements[MAXITEM];

bool IsEmpty(void)
{
    return theLevel == 0;
}

bool IsFull(void)
{
    return theLevel == MAXITEM;
}

void Push(StackItem item)
{
    if(!IsFull())
        theElements[theLevel++] = item;
}

StackItem Pop(void)
{
    if(!IsEmpty())
        return theElements[--theLevel];

    return (StackItem) 0;
}

int StackLevel(void)
{
    return theLevel;
}