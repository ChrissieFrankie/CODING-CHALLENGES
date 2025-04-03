#include <stdio.h>
#include <stdlib.h>

typedef struct Count // Create a bitfiled to store the frequency of a letter in a word
{
    unsigned int value : 4;
} Count;

typedef struct LetterNode // Create a node to store the info of a word's letter
{
    unsigned char letter;
    Count* count;
} LetterNode;

LetterNode* createLetterNode(char letter)
{
    LetterNode* letterNode = (LetterNode*)malloc(sizeof(LetterNode));
    letterNode->letter = letter;
    letterNode->count = (Count*)malloc(sizeof(Count));
    letterNode->count->value = 1;
    return letterNode;
}

int main(void)
{
    printf("Hello, World!\n");
    LetterNode* a = createLetterNode('a');
    printf("Letter: %c\n", a->letter);
    printf("Count: %d\n", a->count->value);
    return 0;
}

