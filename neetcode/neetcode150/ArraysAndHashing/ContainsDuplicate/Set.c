/* The Set is more of a trie/tree*/

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct Set // holds decimal values
{
    struct Set *digits[10];
} Set;

Set *create() // Returns a pointer to a new Set
{
    Set *newSet = (Set *)(malloc(sizeof(Set))); // Allocate memory for new Set
    if (newSet == NULL)                         // Still NULL?
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

void add(Set *set, int value)
{
    if (set == NULL) // Null set was provided
    {
        fprintf(stderr, "TRYING TO ADD A VALUE TO A NULL SET\n");
        return;
    }
    int temp = value; // For later
    int product = 1;  // For later
    if (temp > 9)     // Process value
    {
        while (temp > 9) // Traverse digits
        {
            temp /= 10; // Remove last digit
            product *= 10;
        }
    }
    if (set->digits[temp] == NULL)
    {
        set->digits[temp] = (Set *)(malloc(sizeof(Set))); // Record index corresponding to digit
        if (set->digits[temp] == NULL)                    // Didn't allocate memeory
        {
            fprintf(stderr, "UNABLE TO ALLOCATE MEMEORY FOR SET AT INDEX %d\n", temp);
            return;
        }
        for (int i = 0; i < 10; i++) // Initialize digits array
        {
            set->digits[temp]->digits[i] = NULL;
        }
    }
    int remainder = value % product;
    if (product != 1) // There are more digits to save
    {
        add(set->digits[temp], remainder);
    }
}

bool exists(Set *set, int value)
{
    if (set == NULL) // Null set was provided
    {
        fprintf(stderr, "TRYING TO CHECK A SET THAT DOESN'T EXIST\n");
        return false;
    }
    int temp = value; // For later
    int product = 1;  // For later
    if (temp > 9)     // Process value
    {
        while (temp > 9) // Traverse digits
        {
            temp /= 10; // Remove last digit
            product *= 10;
        }
    }
    if (set->digits[temp] != NULL) // Digit exists
    {
        if (product == 1) // Single digit left
        {
            return true; // Value exists
        }
        else // There are more digits to check
        {
            int remainder = value % product;
            return exists(set->digits[temp], remainder); // Continue checking
        }
    }
    else
    {
        return false; // No value
    }
}

void remove(Set *set, int value)
{
    if (set == NULL) // Null set was provided
    {
        fprintf(stderr, "TRYING TO ADD A VALUE TO A NULL SET\n");
        return;
    }
    int temp = value; // For later
    int product = 1;  // For later
    if (temp > 9)     // Process value
    {
        while (temp > 9) // Traverse digits
        {
            temp /= 10; // Remove last digit
            product *= 10;
        }
    }
    if (set->digits[temp] != NULL) // The digit exists
    {
        if (product == 1) // The only digit
        {
            free(set->digits[temp]);  // Digit no longer needed
            set->digits[temp] = NULL; // Value scraped
        }
        else
        {
            int remainder = value % product;
            remove (set->digits[temp], remainder); // We continue the deletion process
        }
    }
    // Value doesn't exist, why bother
}

int main(void)
{
    Set *digits = create(); // We've created our digits set
    add(digits, 998);
    printf("DOES 998 EXIST? %d\n", exists(digits, 998));
    printf("DOES 999 EXIST? %d\n", exists(digits, 999));
    remove(digits, 998);
    printf("DOES 998 EXIST? %d\n", exists(digits, 998));
    printf("DOES 999 EXIST? %d\n", exists(digits, 999));
    printf("HELLO WORLD!\n");
    return 0;
}