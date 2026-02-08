# Creating LYNX functions to extend usage

making your own functions that work with LYNX is very straightforward if you follow the guide:

## step 1:

the first step is to right your functions in accordance with the LYNX function caller

functions are always void:

my_function.c
```c
void my_function() {
    // do things
}
```

in addition they also take two string variables as parameters, it is recomended to use arg1 and arg2

```c
void my_function(char arg1[], char arg2[]) {
    // do things
}
```

## step 2

the second step is to make a header file:

my_function.h
```c
#ifndef MY_FUNCTION_H
#define MY_FUNCTION_H

void my_function(char arg1[], char arg2[]);

#endif
```
then put it in the "include" directory

## step 3

the third step is to add it to the lookup table

locate look_up_table.c and add this line to the top

```c
#include "my_function.h"
```

then add it as a function pointer:

you should see some lines that look like this:

```c
struct funcptrs all_functions[] = {
    {"add", add},
    {"print", print},
    {"let", let},
};
```

append your line below the others:
```c
{"my_function", my_function},
```

## that's it!

you now have added your own LYNX function and expanded functionality

recompile:

```bash
make
```

and run:

```bash
cd build
./lynx filename.lynx
```

now you can type "my_function" and it will be treated as a valid lynx command;



