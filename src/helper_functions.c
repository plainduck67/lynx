#include "global_values.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// ########################################
// ## HELPER FUNCTIONS -- DO NOT REMOVE! ##
// ########################################

int find_variable(char string[]) {
    for (int i = 0; i <= MAX_VARS; i++) {
        if (strcmp(string, var[i].name) == 0) {
            return i;
        }
    }
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
}

// ############################################################
// ## END OF HELPER FUNCTIONS -- FEEL FREE TO ADD AND REMOVE ##
// ############################################################
