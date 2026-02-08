#include "look_up_table.h"
#include <stdio.h>
#include <string.h>

#define AMOUNT_OF_STRINGS 6
#define LENGTH_PER_STRING 50

void parse(char string[]) {
    char array[AMOUNT_OF_STRINGS][LENGTH_PER_STRING] = {0};
    int j = 0;
    int k = 0;
    for (int i = 0; string[i] != '\0'; i++) {

        if (string[i] == ' ') {
            array[j][k] = '\0';
            k = 0;
            j++;
        } else {
            array[j][k] = string[i];
            k++;
        }
    }
    array[j][k] = '\0';
    lookup(array[0], array[1], array[2]);
}
