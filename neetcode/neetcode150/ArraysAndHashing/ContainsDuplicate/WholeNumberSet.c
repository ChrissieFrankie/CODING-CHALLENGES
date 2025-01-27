/*
    this is more of a trie/tree
    but the digits are extracted from the least place
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIGITS_COUNT (10)

typedef struct WholeNumberSet // Used to store all the digits used
{
    struct WholeNumberSet* digits[DIGITS_COUNT]; // 0 through 9
    bool* terminates[DIGITS_COUNT];
} WholeNumberSet;

WholeNumberSet* newWholeNumberSet() // Used to create a new set
{
    WholeNumberSet* set = (WholeNumberSet*)(malloc(sizeof(WholeNumberSet))); // Allocate memory for set
    if (set == NULL) // set is still NULL
    {
        fprintf(stderr, "FAILED TO ALLOCATE MEMORY FOR SET!\n");
        return NULL;
    }
    for (int i = 0; i < DIGITS_COUNT; i++) // Set everything to NULL
    {
        set->digits[i] = NULL;
        set->terminates[i] = NULL;
    }
    return set;
}

void freeWholeNumberSet(WholeNumberSet* set) // Free everything in the set
{
    if (set == NULL) // the set is NULL
    {
        fprintf(stderr, "FAILED TO FREE MEMEORY OF A NULL SET!\n");
        return;
    }
    for (int i = 0; i < DIGITS_COUNT; i++) // Iterate through each value
    {
        if (set->terminates[i] != NULL) // Assure bool* is not null
        {
            free(set->terminates[i]);
        }
        if (set->digits[i] != NULL) // Assure WholeNumberSet* is not null
        {
            freeWholeNumberSet(set->digits[i]);
        }
    }
    free(set);
}

int main(void)
{
    WholeNumberSet* set = newWholeNumberSet();
    freeWholeNumberSet(set);
    printf("WORKS!\n");
    return 0;
}