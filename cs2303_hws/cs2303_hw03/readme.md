# CS2303_HW03

For this assignment, 2 testers were created:
1. ctest – this tests the functionality of functions from "mystring.h"
2. student_test - This tests functionality of the student struct.


## Compilation
To compile the program, open the directory into any unix environment and enter make to compile all the source files.
```bash
  $ cd <path to directory>/cs2303_hw03
  ~/<path to directory>/cs2303_hw03$ make
```
**Note**: To compile individual testers enter `make ctest` or `make student_test`.

To get doxygen output, configure the target folder in the makefile and enter make docs. 

```bash
  $ make docs
```

## ctest usage
```bash
  $ ./ctest 
```
**Note**: This program doesn't require any input.

## student_test usage
``` bash 
  $ ./student_test <num_students>
``` 

| Parameter    | Type      | Description                |
| :--------    | :-------  | :------------------------- |
| `num_students` | `integer` | **Optional**. Number of students to include in wpi struct collection. |

**Note**: If no valid number is entered, default wpi_size is 3.

## sample ctest output
```bash
$ ./ctest
Arrays:   a1: 0xffffcfba2f00, a2: 0xffffcfba3020, a3: 0xffffcfba2ee0, b: 0xffffcfba2ec0
Pointers: p1: 0xaaaad9de1910, p2: 0xffffcfba3030, c_copy: 0xffffa88b73c0 

C-string values:
a1:	Hi
a2:	Hello
a3:	Hello, also
b:	012
b_part:	345
c:	ABCDEFG

After concatenating a2 to the end of a1
a1: HiHello

Concatenating a2 to a1, with copy_limit = 13
a1: HiHelloHello

Concatenating a3 to a1, with copy_limit = 8
a1: HiHelloHelloHello, a

mystrncat() Test #1: copy_limit < src
Concatenating 3 char(s) of b_part to b
b: 012345

mystrncat() Test #2: copy_limit = n
Concatenating 4 char(s) of b_part to b
b: 012345345

mystrncat() Test #3: copy_limit > n
Concatenating 8 char(s) of b_part to b
b: 012345345345

mystrncpy() Test #1: copy_limit < n
Copying 3 char(s) of c_part to c
c: 123DEFG	 size: 7

mystrncpy() Test #2: copy_limit = n
Copying 8 char(s) of c_part to c
Not NULL terminated
c: 12345678�����	 size: 14

mystrncpy() Test #3: copy_limit > n && copy_limit > src
Copying 14 char(s) of c_part to c
Will be NULL terminated
c: 123456789	 size: 9

Before dup, array a2 = 0xffffcfba3020, contents = Hello
After dup, pointer p2 =  0xaaab1976b6b0, contents = Hello

Before dup, array c = 0xffffcfba2ea0, contents = ABCDEFG
After dup, pointer c_copy to b[0:3] =  0xaaab1976b6d0, contents = ABC
Will be NULL terminated
```

## sample student_test output
```bash
$ ./student_test 2
I will first make a singular student with my info.
―――――――――――――――――――――――――――――――――――――――
Students name: Ryan Mechery
Age: 18	ID#: 00001
Current GPA: 4.00
Memory Address: 0xaaaaf971b6b0

Now I will test making an collection of students.
WPI School Students:
―――――――――――――――――――――――――――――――――――――――
Students name: Nguumwece Eenwewbol
Age: 7	ID#: 80250
Current GPA: 0.43
Memory Address: 0xaaaaf971b6b0
―――――――――――――――――――――――――――――――――――――――
Students name: Mmhnlkkaqe Uecagg
Age: 10	ID#: 75273
Current GPA: 1.50
Memory Address: 0xaaaaf971b720
―――――――――――――――――――――――――――――――――――――――

Now I will test making a shallow copy of the previous collection.
WPI_SHALLOW_COPY School Students:
―――――――――――――――――――――――――――――――――――――――
Students name: Nguumwece Eenwewbol
Age: 7	ID#: 80250
Current GPA: 0.43
Memory Address: 0xaaaaf971b6b0
―――――――――――――――――――――――――――――――――――――――
Students name: Mmhnlkkaqe Uecagg
Age: 10	ID#: 75273
Current GPA: 1.50
Memory Address: 0xaaaaf971b720
―――――――――――――――――――――――――――――――――――――――

Now I will test making the deepest copy of the original collection.
WPI_DEEP_COPY School Students:
―――――――――――――――――――――――――――――――――――――――
Students name: Nguumwece Eenwewbol
Age: 7	ID#: 80250
Current GPA: 0.43
Memory Address: 0xaaaaf971b770
―――――――――――――――――――――――――――――――――――――――
Students name: Mmhnlkkaqe Uecagg
Age: 10	ID#: 75273
Current GPA: 1.50
Memory Address: 0xaaaaf971b7a0
―――――――――――――――――――――――――――――――――――――――

Now I will free all WPI struct pointers from memory.
The original struct with pointers should all point to null.
FREED WPI School Students:
Student 1 of 2 is NULL
Student 2 of 2 is NULL
―――――――――――――――――――――――――――――――――――――――

The deep copy should remain unaffected.
WPI_DEEP_COPY after freeing WPI (should be same as before):
―――――――――――――――――――――――――――――――――――――――
Students name: Nguumwece Eenwewbol
Age: 7	ID#: 80250
Current GPA: 0.43
Memory Address: 0xaaaaf971b770
―――――――――――――――――――――――――――――――――――――――
Students name: Mmhnlkkaqe Uecagg
Age: 10	ID#: 75273
Current GPA: 1.50
Memory Address: 0xaaaaf971b7a0
―――――――――――――――――――――――――――――――――――――――

I will end the testing by freeing all struct pointers from the deep copy.
FREED WPI_DEEP_COPY:
Student 1 of 2 is NULL
Student 2 of 2 is NULL
―――――――――――――――――――――――――――――――――――――――
```
