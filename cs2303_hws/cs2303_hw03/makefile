all: ctest student

ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

student: student.o mystring.o
	gcc student.o mystring.o -o student

student.o: student.c student.h mystring.h
	gcc -c student.c

mystring.o: mystring.c mystring.h student.h
	gcc -c mystring.c

clean: 
	rm -f *.o ctest student

docs:
	doxygen
	cp -p -r ./html/. ~/public_html/cs2303_hw03

