#Makes TablasDeConversion.exe & ConversionTest.exe
#
#

EXE1 = TablasDeConversion.exe
OBJ1 = TablasDeConversion.o Conversion.o
EXE2 = ConversionTest.exe
OBJ2 = ConversionTest.o Conversion.o

CC = gcc
CFLAGS = -std=c11 -I $(INCS) -L $(LIBS)
INCS = "C:/MinGW/include/"
LIBS = "C:/MinGW/lib/"

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1)
	$(CC) $(OBJ1) -o $(EXE1) $(CFLAGS) -D NDEBUG

Conversion.o: Conversion.c
	$(CC) -c Conversion.c -o Conversion.o $(CFLAGS)

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	$(CC) -c TablasDeConversion.c -o TablasDeConversion.o $(CFLAGS)

$(EXE2): $(OBJ2)
	$(CC) Conversion.o ConversionTest.o -o $(EXE2) $(CFLAGS)

ConversionTest.o: ConversionTest.c Conversion.h
	$(CC) -c ConversionTest.c -o ConversionTest.o $(CFLAGS)
