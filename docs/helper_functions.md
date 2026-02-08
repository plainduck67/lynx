# built in helper functions for writing lynx commands

lynx has built in functions that allow easier writing of lynx functions

## is_variable

is_variable lets you check if a string is a variable or not

```c
is_variable(string_parameter);
```

## find_variable

find_variable lets you check the position of a known variable, you should know that that variable exists, and you can check that with is_variable

```c
find_variable(string_parameter);
```

## string_to_value

string_to_value is a function that lets you turn strings into integers

```c
string_to_value(string_parameter);
```
