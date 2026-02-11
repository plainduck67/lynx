#include "parser.h"
#include <stdio.h>
#include <string.h>
#include "global_values.h"
#define MAX_ARGS 6

void indexing_for_loop() {
    for (int z = 0; z < i; z++) {
        parse(entire_program[z + lines_skipped]);
    }
}

void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    char *line = NULL;
    size_t cap = 0;
    ssize_t len;
    while ((len = getline(&line, &cap, fp)) != -1) {
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        strcpy(entire_program[i], line);
        i++;
    }
    indexing_for_loop();
    fclose(fp);
}

int main(int argc, char *argv[]) {

    char filename[50];
    if (argv[1] == NULL) {
        printf("no filename provided - enter below\n");
        if (fgets(filename, sizeof(filename), stdin)) {
            size_t len = strlen(filename);
            if (len > 0 && filename[len - 1] == '\n') {
                filename[len - 1] = '\0';
            }
        }

    } else {
        strcpy(filename, argv[1]);
    }
    char input[128];
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen failed");
        return 1;
    }
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin)) {
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
            }
        }

        if (strcmp(input, "run") == 0) {
            fclose(fp);
            read_file(filename);
        } else {
            fprintf(fp, "%s\n", input);
        }
    }
}
