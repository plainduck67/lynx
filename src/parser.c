#include "look_up_table.h"

#define AMOUNT_OF_STRINGS 6
#define LENGTH_PER_STRING 50

void parse(const char *string) {
    char tokens[AMOUNT_OF_STRINGS][LENGTH_PER_STRING] = {0};
    int token_index = 0; // what token the program is on
    int char_index = 0;  // the index within the token
    for (int i = 0; string[i] != '\0'; i++) {

        if (string[i] == ' ') {
            tokens[token_index][char_index] = '\0';
            char_index = 0;
            token_index++;
        } else {
            tokens[token_index][char_index] = string[i];
            char_index++;
        }
    }
    tokens[token_index][char_index] = '\0';
    lookup(tokens[0], tokens[1], tokens[2]);
}
