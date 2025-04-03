#include <stdio.h>
#include <stdlib.h>

typedef struct Count // Create a bitfiled to store the frequency of a letter in a word
{
    unsigned int value : 4;
} Count;

typedef struct LetterTreeNode // Create a node to store the info of a word's letter
{
    unsigned char letter;
    Count* count;
} LetterTreeNode;

LetterTreeNode* createLetterTreeNode(char letter) // Create a letter node given a letter
{
    LetterTreeNode* letterTreeNode = (LetterTreeNode*)malloc(sizeof(LetterTreeNode));
    letterTreeNode->letter = letter;
    letterTreeNode->count = (Count*)malloc(sizeof(Count));
    letterTreeNode->count->value = 1;
    return letterTreeNode;
}

int main(void)
{
    printf("Hello, World!\n");
    LetterTreeNode* a = createLetterNode('a');
    printf("Letter: %c\n", a->letter);
    printf("Count: %d\n", a->count->value);
    freeLetterNode(a);
    return 0;
}

