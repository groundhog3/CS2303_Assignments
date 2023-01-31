all: lab1

lab1: lab1.o
	gcc --std=gnu89 lab1.o -o lab1

lab1.o: lab1.c
	gcc -c --std=gnu89 lab1.c

clean:
	rm -f lab1.o lab1
