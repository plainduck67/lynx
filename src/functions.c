#include "global_values.h"
#include "helper_functions.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// built-in functions
// feel free to add and remove functions
// for adding functions review the documentation

// adds two numbers by converting the string paramters to integers
void add(char arg1[], char arg2[]) {
    if (is_variable(arg1) == 1 && is_variable(arg2) == 1) {
        const int first_number = string_to_value(arg1);
        const int second_number = string_to_value(arg2);
        last = first_number + second_number;
    }
    else {
        const int found_num1 = find_variable(arg1);
        const int found_num2 = find_variable(arg2);
        last = var[found_num1].value + var[found_num2].value;
    }


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

void ifequal(char arg1[], char arg2[]) {
    int num1 = string_to_value(arg1);
    int num2 = string_to_value(arg2);
    if (num1 == num2) {
       parse(entire_program[i]);
       lines_skipped++;
    }
}
void print(char arg1[], char arg2[]) {
    if (arg1[0] == '"') {
        for (int i = 1; arg1[i] != '"'; i++) {
            printf("%c", arg1[i]);
        }
        printf("\n");

    } else if (is_variable(arg1) == 0) {
        const int found_num = find_variable(arg1);
        printf("%d\n", var[found_num].value);
    } else {
        printf("%s\n", arg1);
    }
}
