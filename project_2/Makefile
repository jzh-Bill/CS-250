input.o: input.c
	clang -c -Wall --pedantic-errors input.c

stack.o: stack.c
	clang -c -Wall --pedantic-errors stack.c

balanced_pairs.o: balanced_pairs.c
	clang -c -Wall --pedantic-errors balanced_pairs.c

balanced_pairs: balanced_pairs.o input.o stack.o
	clang -o balanced_pairs balanced_pairs.o stack.o input.o
all: balanced_pairs

clean:
	rm -f balanced_pairs balanced_pairs.o input.o stack.o balanced_pairs.tar
tarball: balanced_pairs
	tar -c -f balanced_pairs.tar balanced_pairs.c input.c input.h stack.c stack.h Makefile

