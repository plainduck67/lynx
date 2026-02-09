#include "functions.h"
#include <stdio.h>
#include <string.h>

#define NUM_FUNCS 3

struct func_ptrs {
    const char *name;
    void (*func)(char arg1[], char arg2[]);
};

struct func_ptrs all_functions[] = {
    {"add", add},
    {"print", print},
    {"let", let},
};

void lookup(const char *name, char arg1[], char arg2[]) {
    for (int i = 0; i < NUM_FUNCS; i++) {
        if (strcmp(name, all_functions[i].name) == 0) {
            all_functions[i].func(arg1, arg2);
            return;
        }
    }

    printf("\033[31mERROR:\033[0m function %s does not exist\n", name);
}
