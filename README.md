# LYNX - Linear Notation and eXecution

LYNX is a open-source interpreted language, that is meant to be a c function wrapper

## philosophy:

1. build the runtime you need

LYNX allows you to easily create and modify the funcions so you can make the runtime as small or as large as you need.

if the program you are making doesn't need math, remove those functions, 
need a feature? make a function for it.

2. easy syntax

in LYNX everything is written like a simple c-like function call

example: ```add 1 2```

3. linear usage

in LYNX, programs are written in the LYNX scratchpad from top to bottom.
programs are also executed from top to bottom

4. simplicity

in LYNX there should never be a line you don't understand, every line calls a function you can modify and look at, and they are all easy to locate,

5. Make C a scripting langauge

scripting languages are undeniably usefull, but LYNX allows you to make c a scripting language for your functions

## usage:

It is very simple to use LYNX, if you have a program already written in a different editor, you can type:

```bash
./lynx run filename.lynx
```

if you do not have a program written, you can type:

```bash
./lynx filename.lynx
```

this will create a new file, to append text, you can type LYNX programs line by line:

```lynx
add 1 2
let x
print x
```

then type:

```bash
run
```

these assume the binary is compiled, the philophy of LYNX is that you build it yourself:

```bash
make
```

this produces a LYNX binary in /build/
