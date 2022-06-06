#include "studio.h"

/*el prototipo de 'prontf' está declarado en 'studio.h' pero
 no está definido allí, por lo que 'prontf' deberá ser resuelta
 por el linker para que luego de su invocación se ejecute el código
 correspondiente, el cual sí está definido en libstudio2.a*/
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}