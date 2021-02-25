all:	main
main:	main.o 
		gcc -g -o main main.o -lm
main.o:	main.c
	gcc -g -c main.c -lm
clean:	
	rm -f *.o 
