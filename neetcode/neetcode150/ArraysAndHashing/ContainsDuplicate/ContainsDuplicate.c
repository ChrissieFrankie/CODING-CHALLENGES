#include <stdio.h>
#include <Set.h>
#include <stdbool.h>

bool containsDuplicateUno(int* nums, int numsSize) // Solution uno
{
    Set* set = create(); // Create set
    for (int i = 0; i < numsSize; i++) // Iterate through nums
    {
        if (exists(set, nums[i])) // If the num already exists
        {
            return true; // There are duplicates
        }
        add(set, nums[i]); // Keep adding nums to the set
    }
    freeSet(set);
    return false; // No duplicates
}

int main(void)
{
    int arrayOne[4]; // Test case one
    arrayOne[0] = 1;
    arrayOne[1] = 2;
    arrayOne[2] = 3;
    arrayOne[3] = 1;
    printf("Does array [1 2 3 1] contain duplicates?: %d\n", containsDuplicateUno(arrayOne, 4));

    int arrayTwo[4]; // Test case two
    arrayTwo[0] = 1;
    arrayTwo[1] = 2;
    arrayTwo[2] = 3;
    arrayTwo[3] = 4;
    printf("Does array [1 2 3 4] contain duplicates?: %d\n", containsDuplicateUno(arrayTwo, 4));

    return 0;
}

