rotate: rotate.o shift.o
	clang -o rotate rotate.o shift.o

rotate.o: rotate.c shift.h
	clang -c -Wall --pedantic-errors rotate.c

shift.o: shift.c shift.h
	clang -c -Wall --pedantic-errors shift.c

all:	rotate

clean:
	rm -f shift.o rotate.o rotate
