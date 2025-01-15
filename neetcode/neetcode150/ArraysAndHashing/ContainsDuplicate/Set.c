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

int main(void)
{
    Set* digits = create(); // we've created our digits set
    printf("HELLO WORLD!\n");
    return 0;
}