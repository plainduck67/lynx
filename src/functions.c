#include "global_values.h"
#include "helper_functions.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
// built-in functions
// feel free to add and remove functions
// for adding functions review the documentation

void add(char arg1[], char arg2[]) {
    const int first_number = string_to_value(arg1);
    const int second_number = string_to_value(arg2);
    last = first_number + second_number;
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

void sub(char arg1[], char arg2[]) {
    int num1 = string_to_value(arg1);
    int num2 = string_to_value(arg2);
    last = num1 - num2;
}

void mul(char arg1[], char arg2[]) {
    int num1 = string_to_value(arg1);
    int num2 = string_to_value(arg2);
    last = num1 * num2;
}

void div(char arg1[], char arg2[]) {
    int num1 = string_to_value(arg1);
    int num2 = string_to_value(arg2);
    last = num1 / num2;
}

void scan(char arg1[], char arg2[]) {
    char temp[100];
    scanf("%s", temp);
    strcpy(var[var_count].name, arg1);
    var[var_count].value = string_to_value(temp);
    var_count++;
}
