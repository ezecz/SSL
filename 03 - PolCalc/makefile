# Makes Calculator.exe
#
#

EXE = Calculator.exe
OBJ = Calculator.o StackOfDoublesModule.o

CC = mingw32-gcc
CFLAGS = -std=c11 -I $(INCS) -L $(LIBS)
INCS = "C:/MinGW/include/"
LIBS = "C:/MinGW/lib/"

DEF = def.l
FLEX = flex

# Versión "manual" del Scanner
PolCalc: $(OBJ) Scanner.o
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) Scanner.o

# Versión "automática" del Scanner, utiliza flex
PolCalcLex: $(OBJ) lex.yy.o
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) lex.yy.o

Calculator.o: Calculator.c Scanner.h StackOfDoublesModule.h
	$(CC) $(CFLAGS) -c Calculator.c -o Calculator.o

Scanner.o: Scanner.c Scanner.h
	$(CC) $(CFLAGS) -c Scanner.c -o Scanner.o

StackOfDoublesModule.o: StackOfDoublesModule.c StackOfDoublesModule.h
	$(CC) $(CFLAGS) -c StackOfDoublesModule.c -o StackOfDoublesModule.o

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c -o lex.yy.o

lex.yy.c: $(DEF)
	$(FLEX) --nodefault $(DEF)

clean:
	del $(EXE)
	del $(OBJ)
	del lex.yy.o
	del lex.yy.c
