# LYNX documentation

## existing functions:

## 1. let

let allows you to capture and set variables.

examples:

```lynx
let x 5
```
that sets the value 5 to x

if you want to make x equal to the output of the last function you can "catch" it:

```lynx
add 1 2
let x
print x
```
that should print "3" to the console

## 2. print

print allows you to print text to the console

print variables:

```lynx
print x
```
print text:

```lynx
print "hello world"
```

## 3. add

add allows you to add 2 numbers together, the output can be captured

```lynx
add 1 2
let x
print x
```
that should print "3" to the console