#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FUNCS 3

struct funcptrs {
    const char *name;
    void (*func)(char arg1[], char arg2[]);
};

struct funcptrs all_functions[] = {
    {"add", add},
    {"print", print},
    {"let", let},
};

void lookup(const char *name, char num1[], char num2[]) {
    for (int i = 0; i < NUM_FUNCS; i++) {
        if (strcmp(name, all_functions[i].name) == 0) {
            all_functions[i].func(num1, num2);
            return;
        }
    }

    printf("\033[31mERROR:\033[0m function %s does not exist\n", name);
}
