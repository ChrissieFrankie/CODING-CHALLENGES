/*
    this is more of a trie/tree
    but the digits are extracted from the least place
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct WholeNumberSet
{
    struct WholeNumberSet* digits[10]; // 0 through 9
    bool terminates[10];
} WholeNumberSet;


int main(void)
{
    return 0;
}