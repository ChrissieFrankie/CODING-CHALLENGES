#include "stdio.h"

typedef struct Set // holds decimal values
{
    struct Set* digits[10];
} Set;

Set* create() // Returns a pointer to a new Set
{
    Set* newSet = (Set*)(malloc(sizeof(Set))); // Allocate memory for new Set
    if (newSet == NULL) // Still NULL?
    {
        fprintf(stderr, "UNABLE TO ALLOCATE MEMORY FOR NEW SET!\n"); // Throw error
        return NULL;
    }
    for (int i = 0; i < 10; i++)
    {
        newSet->digits[i] = NULL;
    }
    return newSet;
}

void add(Set* set, int value)
{
    if (set == NULL) // a null set was provided
    {
        fprintf(stderr, "TRYING TO ADD A VALUE TO A NULL SET\n");
        return;
    }
    int temp = value; // for later
    int product = 1; // for later
    if (temp > 9) // process value
    {
        while (temp > 9) // traverse digits
        {
            temp /= 10; // remove last digit
            product *= 10; 
        }
    }
    set->digits[temp] = (Set*)(malloc(sizeof(Set))); // record index corresponding to digit
    if (set->digits[temp] == NULL) // didn't allocate memeory
    {
        fprintf(stderr, "UNABLE TO ALLOCATE MEMEORY FOR SET AT INDEX %d\n", temp);
        return;
    }
    int remainder = value % product;
    if (product != 1) // there are more digits to save
    {
        add(set->digits[temp], remainder);
    }
}

int main(void)
{
    Set* digits = create(); // we've created our digits set
    printf("HELLO WORLD!\n");
    return 0;
}