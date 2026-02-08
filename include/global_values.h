#ifndef GLOBAL_VALUES_H
#define GLOBAL_VALUES_H

#define MAX_VARS 10

struct variables {
    char name[50];
    int value;
};

extern int var_count;
extern int last;
extern struct variables var[MAX_VARS];

#endif
