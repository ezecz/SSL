# Secuencia de Pasos

## 1. Preprocesador
**a)** Se escribió _hello2.c_, que es una variante de _hello.c_.

**b)** Luego de escribir _hello2.c_, se lo ha preprocesado a un archivo _hello2.i_.

Echando un vistazo al archivo preprocesado, se ve que hay varias lineas cuyo contenido son ubicaciones
hacia archivos header (.h). Estas son las dependencias del _stdio.h_ incluido en _hello2.c_, además de las dependencias de sus dependencias (y así sucesivamente).
Evidentemente, el preprocesador busca todas las dependencias necesarias del _hello2.c_ y las copia-y-pega en _hello2.i_, que es el archivo que pasará a compilarse.
No hay errores de compilación (aún), ya que sólo se ha buscado preprocesar.

**c)** Se escribió _hello3.c_, que es una variante de _hello2.c_ la cual tiene el prototipo de 'printf' pero no el #include.

**d)** La primera línea de _hello3.c_ está declarando el prototipo de printf. Básicamente, se está diciendo que esta invocación recive un puntero a char constante y recibe un entero.
Además, en el prototipo se ve como parámetro a la Ellipsis (...), la cual permitirá pasarle a 'printf' una cantidad arbitraria de argumentos cuando se la invoque.
Por último, se ve la keyword 'restrict', la cual, semánticamente hablando, no agrega nueva funcionalidad, pero pragmáticamente se usa para optimizaciones en cuanto al llamado de la función.

**e)** Se ha preprocesado _hello3.c_ en _hello3.i_. La diferencia a simple vista con _hello2.i_ es el tamaño de los archivos; _hello3.i_ tiene unas 10 lineas, mientras que _hello2.i_ tiene mas de 400! Esto se debe
a que _hello3.c_ no incluyó a _stdio.h_ (como sí lo hizo _hello2.c_), por lo que todas las inclusiones, declaraciones y definiciones no se tuvieron en cuenta para preprocesar. Sólo se dejó el código escrito
en _hello3.c_.


## 2. Compilación
**a)** Se compiló el archivo _hello3.c_ y, como era de esperarse, el compilador arrojó errores de compilación (la función main no termina con '}').

**b)** Se renombró _hello3.c_ a _hello4.c_ y se le ha agregado la llave que faltaba, por lo que _hello4.c_ logró ser compilado.

**c)** El compilador arrojó un archivo .s, el cual contiene lenguaje el ensamblador de nuestro código.
Básicamente, se inicia preparándose los registros para el uso de la stack. Luego se hace un llamado a una función desconocida. Posteriormente se
asigna 42 a la primer variable automática, almacenada en la stack, y al principio de esta se le asigna la dirección de 'LCO', que es el único string de nuestro programa.
Estas variables serán pasadas a 'prontf', la cual debería leer los argumentos directamente de la stack. Por último, se le asigna un cero al registro acumulador (en algunas
convenciones se usa este registro para indicar el valor retornado) y luego se sale de 'LFB0' con la instrucción 'ret'.

**d)** Se ha compilado y ensamblado _hello4.c_, y el compilador ha arrojado un archivo Objeto, el cual contiene código máquina.

## 3. Vinculación
**a)** Se ha intentado vincular _hello4.c_ con la biblioteca estándar pero, como era de esperarse, no resuelve la referencia a 'prontf', informando el error: "undefined reference to `prontf'.

**b)** Se ha corregido lo necesario para la vinculación con la biblioteca estándar en _hello5.c_. Se ha compilado y vinculado _hello5.c_ y el proceso de traducción culmina en el archivo _hello5.exe_.

**c)** Se ha ejecutado _hello5.exe_ y se ha visto un Bug: no se ha impreso lo que se esperaba.

## 4. Corrección del Bug
**4)** Se ha arreglado el Bug pasándole la variable 'i' a 'printf' en un nuevo archivo _hello6.c_, el cual se compiló, se ejecutó y funcionó como se esperaba.

## 5. Remoción de tipo
**a)** Se ha removido la declaración de 'printf' en _hello6.c_, y se ha renombrado el archivo a _hello7.c_. El programa sigue funcionando como se esperaba.

**b)** El programa sigue funcionando con los nuevos cambios ya que gcc hace inferencias basándose en el nombre de la función 'printf' y hace que nuestro código se vincule automáticamente con la biblioteca estándar, ya que asume que
nuestra 'printf' es la de la biblioteca estándar.

## 6. Compilación Separada: Contratos y Módulos
**a)** Se ha escrito _studio1.c_ y _hello8.c_. En _studio1.c_ se define 'prontf' y se la usa en _hello8.c_.

**b)** Se ha generado _hello8.exe_ pasandole a gcc los dos archivos fuente corriendo el siguiente comando: _gcc studio1.c hello8.c -o hello8.exe_

Luego se corrió el ejecutable y funcionó como se esperaba.

**c)** Si se agregan o eliminan argumentos a la invocación de prontf, sigue sin haber errores de compilación, pues en _hello8.c_ no se le indica al compilador el cómo debe usarse 'prontf'.

**d)** Se han escrito los siguientes archivos: _studio.h_, _hello9.c_ y _studio2.c_. El header studio.h tiene el contrato, _studio2.c_ tiene la implementación y _hello9.c_ hace uso de ella.
En este caso, agregar o eliminar argumentos en la invocación de 'prontf' arroja error de compilación, debido a que no se está cumpliendo su prototipo (o contrato) declarado en _hello9.c_ mediante el #include.

La ventaja de incluir el contrato en los clientes y en el proveedor es que el compilador asegura que ambas partes usan la interfaz de la misma manera, sin errores en la invocación por parte del cliente, ni errores en la implementación por parte del proveedor.

## Crédito Extra
Las bibliotecas son archivos que contienen porciones de código pre-compilado y reutilizable. Al ser archivos separados, son distribuibles, por lo que, si linker admite dichos archivos, puede hacer que el programa use el código definido en ellos.
Debido a que las bibliotecas contienen código máquina, la portabilidad va a depender de si tal biblioteca fue compilada para la misma arquitectura que en la que se usará (no se puede usar una biblioteca compilada para x86 en un sistema ARM, por ejemplo).
A continuación se explican ventajas y desventajas de las bibliotecas en general (sin distinguir entre estáticas y dinámicas):

La ventaja principal es que, del lado del cliente, facilitan el desarrollo ya que no es necesario implementar su funcionalidad, simplemente se hace uso de ella de la manera en que lo define la interfaz (la cual debería proveerse junto con la biblioteca en sí).

En cuanto a las desventajas, las bibliotecas tienen los problemas de compatibilidad antes mencionados. En el caso de las bibliotecas estáticas, al estar embebidas en el ejecutable final, pueden ocupar demasiado lugar en disco, sobretodo si se tienen varios programas que fueron vinculados con la misma biblioteca estática.
En el caso de las bibliotecas dinámicas, estas presentan problemas de compatiblidad entre sistemas operativos. Por ejemplo, un .dll no puede usarse en Linux, así como un .lib puede usarse en Windows.

En el proyecto se agrega el ejemplo _hello10TestLib.c_, el cual hará uso de _libstudio2.a_ con la interfaz definida en _studio.h_ del punto 9.d.i). La funcionalidad de _libstudio2.a_ fue implementada en el archivo _studio2.c_ del punto 9.d.iii).

Para la creación de la biblioteca se usó el siguiente comando: _ar rcs libstudio2.a studio2.o_
