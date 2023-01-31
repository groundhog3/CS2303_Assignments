
# CS2303_HW02

For this assignment three programs were created:
1. at – This program demonstrates fixed size integer arrays in C.
2. at2 – This program takes in an array of doubles from the command line, prints them, sorts them, and prints them out again.
3. at3 – This program generates an array of random integers, prints them, sorts them, and prints them out again.

## Compilation

To run the program, open the directory into any unix environment and enter make to compile all the source files.
```bash
  $ cd <path to directory>/cs2303_hw02
  ~/<path to directory>/cs2303_hw02$ make
```

To get doxygen output, configure the target folder in the makefile and enter make docs. 

```bash
  $ make docs
```

## at usage

```bash
  $ ./at 
```

This program doesn't require input from the command line.

Note: This program only prints out 10 integers due to the **INT_ARRAY_SIZE** constant in at.c which can be changed.
## at2 usage

```bash
  $ ./at2 double1 double2 double3 double4 double5 double6 double7 double8 double9 double10
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `double1` | `double` | **Required**. Any valid double. |
| `double2` to `double10` | `double` | Any valid double as well |

This program is only designed to handle a maximum of 10 floats due to the **DOUBLE_ARRAY_SIZE** constant in at2.c. This can be changed to handle more input. 

Entering any more or any less will result in an error.
## at3 usage

```bash
  $ ./at3 max_random num_randoms 
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `max_random` | `integer` | **Required**. Maximum random  number to be populated within the array (inclusive). |
| `num_randoms` | `integer` | **Required**. Number of items to be stored in the array. |


This program only requires these two inputs. Entering any more or less will result in an error.


## Tests

1. at tests

```bash
  $ ./at
  0
  1
  2
  3
  4
  5
  6
  7
  8
  9
```

```bash 
$ ./at 10
This program requires no inputs. Try again!
```

2. at2 tests

```bash
$ ./at2 5.5 10.3 3.7 6.5
Before Sorting:
5.500000
10.300000
3.700000
6.500000
After Sorting:
3.700000
5.500000
6.500000
10.300000
```

```bash
$ ./at2 
No arguments were entered. Try again.
```

```bash
$ ./at2 1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.1 11.2
The array can only hold 10 elements. You entered 11 elements.
Try again with fewer parameters.
```

3. at3 tests

```bash
2$ ./at3 10 8
Before Sorting:
9
4
10
6
4
3
0
2
After Sorting:
0
2
3
4
4
6
9
10

```
```bash
$ ./at3 10 8
Before Sorting:
2
5
10
6
2
4
8
2
After Sorting:
2
2
2
4
5
6
8
10

```
```bash
$ ./at3 
Enter an argument into the command line!

```

```bash
$ ./at3 10
You entered 1 argument(s). This program requires exactly 2.
```