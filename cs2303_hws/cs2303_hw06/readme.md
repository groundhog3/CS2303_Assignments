# CS2303_HW06

For this assignment, 2 programs were created.
1. `fed2cs2303`: this program was finished in lab06 and parses a CSV from federal govt.
2. `zipcode`: this program reads csv created by `fed2cs2303` and allows user to filter data from it.

# Compilation 
To compile the program, open the directory into any unix environment and enter make to compile all the source files.
```sh
$ cd <path to directory>/cs2303_hw06
~/<path to directory>/cs2303_hw06$ make
```
**Note**: To compile individual testers enter `make fed2cs2303` or `make zipcode`.

To get doxygen output, configure the target folder in the makefile and enter make docs.
```sh
$ make docs
```

To remove object files and executables, run this command:
```sh
$ make clean
```

# fed2cs2303 usage
```sh
$ ./fed2cs2303 input_file output_file
```
| Parameter | Type   | Description |
| ---       | ---    | --- |
| `input_file`    | file path    | **Required**. File Path of input csv. |
| `output_file`    | file path    | **Required**. File Path to write to. New one will be created if not found. |

**Note**: Due to the `SZ_FILENAME` preprocesser directive, both file paths can only be a max of 129 characters only.

# zipcode usage
```sh
$ ./zipcode input_file
```

| Parameter | Type   | Description |
| ---       | ---    | --- |
| `input_file`    | file path    | **Required**. File Path of input csv formatted by `fed2cs2303`. |

**Note**: Due to the `SZ_FILENAME` preprocesser directive, both file paths can only be a max of 129 characters only.

**Note**: Due to the `MAXLINE` preprocesser directive, command line inputs can only be a max of 4096 characters. 

# fed2cs2303 tests
```sh
$ ./fed2cs2303 
usage: ./fed2cs2303 input_file output_file
```

```sh
$ cat output.csv
$ ./fed2cs2303 free-zipcode-database.csv output.csv
$ cat output.csv
02636,STANDARD,CENTERVILLE,MA,41.639999,-70.339996
02239,UNIQUE,COM/ENERGY SERVICES,MA,42.360001,-71.099998
(...)
```

# zipcode tests

```sh
$ ./zipcode 
usage: ./zipcode input_file
```

```sh
$ ./zipcode output.csv
All items from output.csv were processed successfully!

Enter city names line by line: (CTRL+D to stop)
_ WORCESTER
01601
01602
01603
01604
01605
01606
01607
01608
01609
01610
01612
01613
01614
01615
01653
01654
01655
_ 
```

```sh
$ ./zipcode output.csv
All items from output.csv were processed successfully!

Enter city names line by line: (CTRL+D to stop)
_ aUbUrN
01501
_ bOsToN
02108
02109
02110
02111
02112
02113
02114
02115
02116
02117
02118
02119
02120
02121
02122
02123
02124
02125
02126
02127
02128
02129
02130
02131
02132
02133
02134
02135
02136
02137
02163
02196
02199
02201
02203
02204
02205
02206
02210
02211
02212
02215
02217
02222
02228
02241
02266
02283
02284
02293
02295
02297
02298
02207
02216
_ 
```
**Note**: Extra credit is demonstrated here.

