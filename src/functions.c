#include "global_values.h"
#include "helper_functions.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// built in functions
// feel free to add and remove functions
// for adding functions review the documentation

void add(char num1[], char num2[]) {
    int x = string_to_value(num1);
    int y = string_to_value(num2);
    last = x + y;
}

void let(char arg1[], char arg2[]) {
    strcpy(var[var_count].name, arg1);
    if (arg2 == NULL || arg2[0] == '\0') {
        var[var_count].value = last;
    } else {
        var[var_count].value = string_to_value(arg2);
    }
    var_count++;
}

void print(char arg1[], char arg2[]) {
    int found_num;
    if (arg1[0] == '"') {
        for (int i = 1; arg1[i] != '"'; i++) {
            printf("%c", arg1[i]);
        }
        printf("\n");

    } else if (is_variable(arg1) == 0) {
        found_num = find_variable(arg1);
        printf("%d\n", var[found_num].value);
    } else {
        printf("%s\n", arg1);
    }
}
