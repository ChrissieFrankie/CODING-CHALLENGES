#ifndef SET_H
#define SET_H

typedef struct Set
{
    struct Set* digits[10];
} Set;

void create();
void add(Set* set, int value);
bool exists(Set* set, int value);
void remove(Set *set, int value);


#endif