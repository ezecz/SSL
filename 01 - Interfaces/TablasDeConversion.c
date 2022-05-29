/*TablasDeConversion.c
 *Desarrollo del código para imprimir las tablas de conversión
 *Ezequiel David Czerniak
 *30/05/2022
*/

#include <stdio.h>
#include "Conversion.h"

void PrintFila(double d1, double d2)
{
    printf("%.2f\t%.2f\n", d1, d2);
}

void PrintFilas(double (*conv)(double), double lower, double upper, double step)
{
    for(double value = lower; value <= upper; value += step)
        PrintFila(value, (*conv)(value));
}

//Imprime la tabla de Fahrenheit a Celsius
void PrintTablaCelsius(double lower, double upper, double step)
{
    printf("Tabla Fahrenheit a Celsius\n");
    PrintFilas(&Celsius, lower, upper, step);
}

//Imprime la tabla de Celsius a Fahrenheit
void PrintTablaFahrenheit(double lower, double upper, double step)
{
    printf("Tabla Celsius a Fahrenheit\n");
    PrintFilas(&Fahrenheit, lower, upper, step);
}

void PrintTablas(double lower, double upper, double step)
{
    PrintTablaCelsius(lower, upper, step);
    printf("\n");
    PrintTablaFahrenheit(lower, upper, step);
}

int main()
{
    const double LOWER = 0.0;
    const double UPPER = 300.0;
    const double STEP = 20.0;
    
    PrintTablas(LOWER, UPPER, STEP);

    return 0;
}