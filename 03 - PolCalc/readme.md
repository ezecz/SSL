# TP 3 - PolCalc

## 1. Diagrama de las dependencias de componentes e interfaces
Se creó el archivo *Dependencias.gv*, el cual será usado por la herramienta *dot* para generar un diagrama que muestre las dependencias del proyecto. El diagrama se puede visualizar en una imagen con formato PNG corriendo el siguiente comando:
```
dot -Tpng Dependencias.gv -o Dependencias.png
```
La flecha desde 'a' hasta 'b' indica que 'a' depende de 'b', por lo que será necesario recompilar 'a' si se modifica 'b'.

## 2. Digrafo de la máquina de estados que implementa GetNextToken()
Se creó el archivo *Scanner.gv*, el cual será usado por la herramienta *dot* para generar un diagrama que represente la máquina de estados implementada por GetNextToken(). El digrafo se puede visualizar en una imagen con formato PNG corriendo el siguiente comando:
```
dot -Tpng Scanner.gv -o Scanner.png
```
(PENDIENTE DEFINICIÓN FORMAL)

## 3. Archivo para probar la calculadora
Se creó un archivo *expresiones.txt* para realizar las pruebas, conteniendo líneas con expresiones en notación prefija. Se quiere probar que las líneas que tienen el léxico correcto arrojen un resultado válido (asumiento que tienen la sintaxis correcta), y las que no, que indiquen qué elementos léxicos no son reconocidos.

## 4. Construcción de la calculadora polaca inversa (versión "manual")
Se construyó un proyecto que compile *Calculator.exe* con los componentes e interfaces indicados en el diagrama del Punto 1. El programa leerá las lineas ingresadas por *stdin* e imprimirá el resultado de la operación, asumiendo que se respeta el léxico, la sintaxis y la semántica para el que fue hecho.

## 6. Respuestas
a) Será necesario modificar *StackOfDoublesModule.h* cuando se quiera modificar la interfaz de la Stack, con lo cual se va a requerir una recompilación del proyecto (salvo el Scanner, el cual no usa dicha interfaz).

b) Será necesario recompilar la implementación de Stack cuando se quiera agregar funcionalidad nueva, o modificar la existente (e.g. cambiar la implementación contigua por la implementación con punteros).

c) A efectos de cumplir su función (mostrar un resultado), no es necesario que muestre el lexema que originó un error léxico, ya que puede saltearse el lexema. Sin embargo, siempre es conveniente informar los errores, ya que se podría agregar código que no funcione bien con un input erróneo.

- i) Se eligió la primera forma de las disponibles. Se agregó un tercer componente en la estructura *Token* llamado *lexeme*, el cual se implementó como cadena de caractéres (arreglo de *char*), y sólo será usado para imprimirse en caso de que no sea token.

- ii) Se decidió implementarlo de la primer forma por una cuestión de expresividad, ya que una cadena de caracteres representa mejor al texto. Se consideró que la segunda forma es ligeramente menos expresiva, ya que requiere agregar un campo que a la vez tiene más campos.

## Construcción de la calculadora polaca inversa (versión "automática")
Se utilizó la herramienta FLEX para generar un Scanner (analizador léxico). Se creó un archivo *def.l* que tiene las reglas sintácticas que definen a los tokens, el cual será usado por FLEX para generar el código fuente del Scanner. Este código será compilado y enlazado junto al resto del proyecto.

La sintaxis de las expresiones se pueden representar con el siguiente BNF:
```
1  Expresión:
2   Número
3   Expresión Expresión Operador
```
En el cual 'Número' y 'Operador' son elementos terminales de la gramática asociada a esta sintaxis, es decir, son tokens.

### Ejemplo de derivación de una expresión correcta
Suponer que se tiene la expresión: \3 1.0 - 11.0 + 2 *\
```
1   Expresión
3   (Expresión Expresión Operador)
3   (Expresión Expresión Operador) Expresión Operador
2   Expresión Expresión Operador (Número) Operador
2   Expresión (Número) Operador Número Operador
3   (Expresión Expresión Operador) Número Operador Número Operador
2   Número (Número) Operador Número Operador Número Operador
2   (Número) Número Operador Número Operador Número Operasdor
       3      1.0      -      11.0     +       2       *
```
Esta expresión es sintácticamente correcta, ya que se ha podido derivar del BNF que implementa la calculadora.

### Ejemplo de derivación de una expresión incorrecta
Suponer que se tiene la expresión: 4 1 * /
```
1   Expresión
3   (Expresión Expresión Operador)
3   (Expresión Expresión Operador) Expresión Operador
2   (Número) Expresión Operador Expresión Operador
2   (Número) (Número) Operador Expresión Operador
Error sintáctico
```
No se puede llegar a la expresión, ya que 'Expresión' no contempla el caractér nulo. Por lo tanto, la expresión no es sintácticamente correcta.