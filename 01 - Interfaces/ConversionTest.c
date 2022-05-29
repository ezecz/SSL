/*ConversionTest.c
 *Desarrollo del código para testear lo definido en Conversion.c
 *Ezequiel David Czerniak
 *30/05/2022
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Conversion.h"

#define SonCasiIguales(a, b) (fabs(a - b) < 1.0)

int main()
{
    printf("Realizando pruebas...\n");

    assert(SonCasiIguales(Celsius(15.0), -9.44));
    assert(SonCasiIguales(Celsius(17.0), -8.33));
    assert(SonCasiIguales(Celsius(140.0), 60.0));

    assert(SonCasiIguales(Fahrenheit(71.0), 160.8));
    assert(SonCasiIguales(Fahrenheit(104.0), 219.2));
    assert(SonCasiIguales(Fahrenheit(115.0), 239.0));

    printf("\nLas pruebas han finalizado bien.\n");
    return 0;
}