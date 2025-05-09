#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Count // Create a bitfield to store the letter frequency
{
    unsigned int value;
} Count;

typedef struct LetterTreeNode // Create a node a store the info of a word's letter
{
    unsigned char letter;
    struct LetterTreeNode *left;
    struct LetterTreeNode *right;
    Count *count;
} LetterTreeNode;

LetterTreeNode *createLetterTreeNode(char letter);
void freeLetterTreeNode(LetterTreeNode *letterTreeNode);
void insertLetterTreeNode(LetterTreeNode **root, char newLetter);
LetterTreeNode *searchLetterTreeNode(LetterTreeNode *root, char letter);
LetterTreeNode *stringToLetterBinaryTree(char *str);
Count *searchLetterCount(LetterTreeNode *root, char letter);
LetterTreeNode *findMinimumLetterTreeNode(LetterTreeNode *root);
LetterTreeNode *deleteLetterTreeNode(LetterTreeNode **root, char letter);
int countTree(LetterTreeNode *root);

#endif