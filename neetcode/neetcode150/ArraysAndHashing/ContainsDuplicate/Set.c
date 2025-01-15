#include "stdio.h"

typedef struct Set // our custom set will hold digit values
{ 
    struct Set* digits;
} Set;

Set* create()
{
    Set* newSet = (Set*)malloc(sizeof(Set)); // we've allocated memory for the new set
    return newSet;
}

int main(void)
{
    Set* digits = create(); // we've created our digits set
    printf("HELLO WORLD!\n");
    return 0;
}