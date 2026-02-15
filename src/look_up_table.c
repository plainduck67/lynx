#include "functions.h"
#include <stdio.h>
#include <string.h>

enum funcs {
    ADD,
    PRINT,
    LET,
    SCAN,
    MUL,
    SUB,
    DIV,
    NUM_FUNCS
};

struct func_ptrs {
    const char *name;
    void (*func)(char arg1[], char arg2[]);
};

struct func_ptrs all_functions[] = {
    {"add", add},
    {"print", print},
    {"let", let},
    {"scan", scan},
    {"mul", mul},
    {"sub", sub},
    {"div", div},
};

void lookup(const char *name, char arg1[], char arg2[]) {
    enum funcs number = NUM_FUNCS;
    for (int i = 0; i < number; i++) {
        if (strcmp(name, all_functions[i].name) == 0) {
            all_functions[i].func(arg1, arg2);
            return;
        }
    }

    printf("\033[31mERROR:\033[0m function %s does not exist\n", name);
}
