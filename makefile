all: Lista

Lista: listaReversivel.o filme.o main.o
	gcc -o Lista listaReversivel.o filme.o main.o

listaReversivel.o: listaReversivel.c listaReversivel.h
	gcc -c listaReversivel.c -Wall -Werror -Wextra

filme.o: filme.c filme.h
	gcc -c filme.c -Wall -Werror -Wextra

main.o: main.c filme.h listaReversivel.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o Lista