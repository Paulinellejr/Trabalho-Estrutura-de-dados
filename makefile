all: Lista

Lista: listaReversivel.o filme.o livro.o vinho.o chocolate.o main.o
	gcc -o Lista listaReversivel.o filme.o livro.o vinho.o chocolate.o main.o

listaReversivel.o: listaReversivel.c listaReversivel.h
	gcc -c listaReversivel.c -Wall -Werror -Wextra

filme.o: filme.c filme.h
	gcc -c filme.c -Wall -Werror -Wextra

livro.o: livro.c livro.h
	gcc -c livro.c -Wall -Werror -Wextra

vinho.o: vinho.c vinho.h
	gcc -c vinho.c -Wall -Werror -Wextra

chocolate.o: chocolate.c chocolate.h
	gcc -c chocolate.c -Wall -Werror -Wextra

main.o: main.c filme.h livro.h vinho.h chocolate.h listaReversivel.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o Lista