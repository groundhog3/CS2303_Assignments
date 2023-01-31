all: ctest oldctest

ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

oldctest: oldctest.o oldmystring.o
	gcc oldctest.o oldmystring.o -o oldctest

oldctest.o: oldctest.c mystring.h
	gcc -c oldmystring.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

clean: 
	rm -f *.o ctest

docs:
	doxygen
	cp -p -r ./html/. ~/public_html/cs2303_hw03

