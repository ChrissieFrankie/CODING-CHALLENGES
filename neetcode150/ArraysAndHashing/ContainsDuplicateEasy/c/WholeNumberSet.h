#include <stdbool.h>

#define DIGITS_COUNT (10)

#ifndef WHOLENUMBERSET_H
#define WHOLENUMBERSET_H

typedef struct WholeNumberSet // Used to store all the digits used
{
    struct WholeNumberSet *digits[DIGITS_COUNT]; // 0 through 9
    bool *terminates[DIGITS_COUNT];
} WholeNumberSet;

WholeNumberSet* newWholeNumberSet();
void add(WholeNumberSet* set, unsigned int number);
bool contains(WholeNumberSet* set, unsigned int number);
void discard(WholeNumberSet* set, unsigned int number);
void freeWholeNumberSet(WholeNumberSet* set);

#endif