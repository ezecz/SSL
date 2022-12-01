// StackOfDoublesModule.h

#include <stdbool.h>

#ifndef STACKOFDOUBLESMODULE_H
#define STACKOFDOUBLESMODULE_H

typedef double StackItem;

bool IsEmpty(void); // Indica si la pila está vacía.
bool IsFull(void); // Indica si la pila está llena.

void Push(StackItem); // Coloca un StackItem en la pila.
StackItem Pop(void); // Saca un StackItem de la pila.

int StackLevel(void); // Retorna el nivel actual de la pila.

#endif