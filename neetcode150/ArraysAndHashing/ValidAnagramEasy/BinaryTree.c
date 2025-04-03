#include <stdio.h>

typedef struct Count // Create a bitfiled to store the frequency of a letter in a word
{
    unsigned int value : 4;
} Count;

typedef struct LetterNode // Create a node to store the info of a word's letter
{
    unsigned char letter;
    Count count;
} LetterNode;

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}

