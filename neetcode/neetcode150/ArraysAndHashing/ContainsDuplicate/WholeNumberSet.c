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
    struct WholeNumberSet *digits[DIGITS_COUNT]; // 0 through 9
    bool *terminates[DIGITS_COUNT];
} WholeNumberSet;

WholeNumberSet *newWholeNumberSet() // Used to create a new set
{
    WholeNumberSet *set = (WholeNumberSet *)(malloc(sizeof(WholeNumberSet))); // Allocate memory for set
    if (set == NULL)                                                          // set is still NULL
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

void freeWholeNumberSet(WholeNumberSet *set) // Free everything in the set
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

void add(WholeNumberSet *set, unsigned int number) // Adds a number to the set
{
    if (set == NULL) // Assure set has been allocated
    {
        fprintf(stderr, "FAILED TO ADD A NUMBER TO AN UNALLOCATED SET!\n");
        return;
    }
    unsigned int digit = number % 10;     // Store the least value
    unsigned int newNumber = number / 10; // Trim to get new value
    if (set->digits[digit] == NULL)       // Need to allocate memory for new digit
    {
        set->digits[digit] = newWholeNumberSet();
    }
    if (newNumber == 0) // Number has terminated
    {
        if (set->terminates[digit] == NULL) // Need to allocate memory for new number
        {
            set->terminates[digit] = (bool *)malloc(sizeof(bool));
            if (set->terminates[digit] == NULL) // Assure bool has been allocated
            {
                fprintf(stderr, "FAILED TO ALLOCATE MEMORY!");
                return;
            }
            *(set->terminates[digit]) = true; // Saved number
            return;
        }
    }
    else
    {

        add(set->digits[digit], newNumber); // Number has more digits
    }
}

int main(void)
{
    WholeNumberSet *set = newWholeNumberSet();
    freeWholeNumberSet(set);
    printf("WORKS!\n");
    return 0;
}