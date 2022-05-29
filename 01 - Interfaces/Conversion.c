/*Conversion.c
 *Implementa las funciones públicas Celsius() y Fahrenheit()
 *Ezequiel David Czerniak
 *30/05/2022
*/

double Celsius(double fahr)
{
    return 5.0 * (fahr - 32.0) / 9.0;
}

double Fahrenheit(double celsius)
{
    return (9.0 * celsius) / 5.0 + 32.0;
}