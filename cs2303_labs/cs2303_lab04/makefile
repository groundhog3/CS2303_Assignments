all: dtest

dtest: dtest.o
	gcc -g dtest.o -o dtest

dtest.o: dtest.c
	gcc -g -c dtest.c

clean:
	rm -f *.o dtest

docs:
	doxygen
	cp -p html/* ~/public_html/cs2303_lab04
