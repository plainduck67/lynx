#include "global_values.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ########################################
// ## HELPER FUNCTIONS -- DO NOT REMOVE! ##
// ########################################

int find_variable(char string[]) {
    for (int i = 0; i < MAX_VARS; i++) {
        if (strcmp(string, var[i].name) == 0) {
            return i;
        }
    }
    return 0;
}

int is_variable(char string[]) {
    for (int i = 0; i <= MAX_VARS; i++) {
        if (strcmp(string, var[i].name) == 0) {
            return 0;
        } else if (i == MAX_VARS) {
            printf("\033[31mERROR:\033[0m variable %s does not exist or is undefined\n", string);
            return 1;
        }
    }
    return 1;
}

int string_to_value(const char *str) {
    if (str[0] != '\0' && str[1] == '\0') {
        if (str[0] >= '0' && str[0] <= '9') {
            return str[0] - '0';
        } else {
            return -1;
        }
    } else {
        return atoi(str);
    }
}


// ############################################################
// ## END OF HELPER FUNCTIONS -- FEEL FREE TO ADD AND REMOVE ##
// ############################################################
