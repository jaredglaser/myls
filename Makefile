all: myls

mycp: main.o 
	gcc -g main.o -o myls

main.o: main.c
	gcc -g -c main.c

clean:
	\rm *.o myls
