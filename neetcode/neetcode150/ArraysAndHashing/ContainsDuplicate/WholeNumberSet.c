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
    while (set != NULL) // Keeps the stack trace shallow
    {
        unsigned int digit = number % DIGITS_COUNT;     // Store the least value
        unsigned int newNumber = number / DIGITS_COUNT; // Trim to get new value
        if (set->digits[digit] == NULL)                 // Need to allocate memory for new digit
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
        set = set->digits[digit];
        number = newNumber; // Number may have more digits
    }
}

bool contains(WholeNumberSet *set, unsigned int number) // Determines whether the number is contained
{
    if (set == NULL) // Assure set has been allocated
    {
        fprintf(stderr, "FAILED TO LOOK UP A NUMBER IN AN UNALLOCATED SET!\n");
        return false;
    }
    while (set != NULL)
    {
        unsigned int digit = number % DIGITS_COUNT;     // Store the least value
        unsigned int newNumber = number / DIGITS_COUNT; // Trim to get new value
        if (set->digits[digit] != NULL)                 // Digit is stored
        {
            if (newNumber == 0)
            {
                if (set->terminates[digit] != NULL) // Terminating flag exists
                {
                    return *(set->terminates[digit]); // Number is contained or not
                }
                else
                {
                    return false; // Number isn't contained
                }
            }
            set = set->digits[digit];
            number = newNumber; // More digits to instigate
        }
        else
        {
            return false; // Number isn't contained
        }
    }
    return false; // Number isn't contained
}

void delete(WholeNumberSet *set, unsigned int number) // Deletes a number
{
    if (set == NULL) // Assure set has been allocated
    {
        fprintf(stderr, "FAILED TO LOOK UP A NUMBER IN AN UNALLOCATED SET!\n");
        return;
    }
    while (set != NULL)
    {
        unsigned int digit = number % DIGITS_COUNT;     // Store the least value
        unsigned int newNumber = number / DIGITS_COUNT; // Trim to get new value
        if (set->digits[digit] != NULL)                 // Digit is stored
        {
            if (newNumber == 0)
            {
                if (set->terminates[digit] != NULL) // Terminating flag exists
                {
                    *(set->terminates[digit]) = false; // Number is deleted
                    free(set->terminates[digit]);
                    set->terminates[digit] = NULL;
                    bool freeDigit = true; // Determine if the digit is being used by any other number
                    for (int i = 0; i < DIGITS_COUNT; i++)
                    {
                        if (set->digits[digit]->digits[i] != NULL)
                        {
                            freeDigit = false; // Found another number using the digit
                        }
                    }
                    if (freeDigit) // True: Proceed without affecting other numbers contained
                    {
                        free(set->digits[digit]);
                        set->digits[digit] = NULL;
                        set = set->digits[digit]; // delete attempt has expired
                    }
                }
                else
                {
                    return; // Number doesn't exist
                }
            }
            else
            {
                set = set->digits[digit];
                number = newNumber; // More digits to instigate
            }
        }
    }
}

int main(void)
{
    WholeNumberSet *set = newWholeNumberSet();
    add(set, 55);
    printf("CONTAINS 55? %d\n", contains(set, 55));
    printf("CONTAINS 5? %d\n", contains(set, 5));
    add(set, 5);
    printf("CONTAINS 55? %d\n", contains(set, 55));
    printf("CONTAINS 5? %d\n", contains(set, 5));
    delete (set, 5);
    printf("CONTAINS 55? %d\n", contains(set, 55));
    printf("CONTAINS 5? %d\n", contains(set, 5));
    delete (set, 55);
    printf("CONTAINS 55? %d\n", contains(set, 55));
    printf("CONTAINS 5? %d\n", contains(set, 5));
    freeWholeNumberSet(set);
    printf("WORKS!\n");
    return 0;
}