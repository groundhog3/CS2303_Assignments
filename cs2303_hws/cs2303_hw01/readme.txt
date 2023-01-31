
# CS2303_Hw01

For this assignment 3 programs were developed.
1. num – This program takes in only one number and returns it.
2. grades – This program takes in a list of grades (max 20) and returns the mean, min, and max of the grades.
3. leap – This program takes in a year and determines if it's a leap year or common year.



## Compilation

The project includes a makefile which compiles all of the files.
Before running the program on your desktop, run the following commands.

```bash
  cd /LOCATION OF FILE/cs2303_hw01
  make
```
    
## num

```bash
./num number
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `number` | `integer` | **Required**. The number you want entered into the program. |

#### Get item



## grades

```bash
./grade grade1 grade2 grade3 grade4 grade5 grade6 grade7 grade8 grade9 grade10 
grade11 grade12 grade13 grade14 grade15 grade16 grade17 grade18 grade19 grade20  
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `grade1` | `integer` | **Required**. A numerical grade you want entered into the program. |
| `grade2` to `grade20` |  `integer` |  Additional numerical grades.

#### Note: The program is only designed to enter a max of 20 grades. Entering any more or none will result in an error. 
This is due to the program's MAX_GRADES constant which can be changed.
## leap

```bash
./leap year
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `year` | `integer` | **Required**. The year you want entered into the program.  |

**Note:** the year must be greater than 1752 due to START_YEAR constant which can be changed. 



## Demo

1. num Tests
```bash
$ ./num 10
The number you entered was: 10.
```

```bash
$ ./num 
Must enter a number on the command line!
```

```bash
$ ./num 10 10
Too many numbers entered.!
```
2. grades Tests
```bash
$ ./grades 93 92 91 81 62 100
The numbers entered were: 93 92 91 81 62 100 
Avg = 86	Min = 62	Max = 100
```
```bash
$ ./grades 
Must enter a number on the command line!
```

```bash
$ ./grades 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
Too many arguments entered!!
```

3. leap
```bash
$ ./leap 1752
The number you entered, 1752, is a leap year.
```

```bash
$ ./leap 1751
This program cannot test the year 1751. It only handles the year 1752 and after.
```

```bash
$ ./leap 1999
The number you entered, 1999, is a common year.
```
```bash
$ ./leap 1900
The number you entered, 1900, is a common year.
```