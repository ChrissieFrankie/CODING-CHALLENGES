#include <stdio.h>
#include <stdlib.h>

typedef struct Count Count;

typedef struct Count // Create a bitfiled to store the frequency of a letter in a word
{
    unsigned int value : 4;
} Count;

typedef struct LetterTreeNode LetterTreeNode;

typedef struct LetterTreeNode // Create a node to store the info of a word's letter
{
    unsigned char letter;
    LetterTreeNode *left;
    LetterTreeNode *right;
    Count *count;
} LetterTreeNode;

LetterTreeNode *createLetterTreeNode(char letter) // Create a letter tree node given a letter
{
    LetterTreeNode *letterTreeNode = (LetterTreeNode *)malloc(sizeof(LetterTreeNode));
    letterTreeNode->letter = letter;
    letterTreeNode->left = NULL;
    letterTreeNode->right = NULL;
    letterTreeNode->count = (Count *)malloc(sizeof(Count));
    letterTreeNode->count->value = 1;
    return letterTreeNode;
}

void freeLetterTreeNode(LetterTreeNode *letterTreeNode) // Free the memory allocated for a letter tree node
{
    if (letterTreeNode != NULL)
    {
        free(letterTreeNode->count);
        freeLetterTreeNode(letterTreeNode->left);
        freeLetterTreeNode(letterTreeNode->right);
        free(letterTreeNode);
    }
}

void insertLetterTreeNode(LetterTreeNode **root, char newLetter) // Insert a letter tree node even if the root is null
{
    if (*root == NULL) // the actual root is null
    {
        *root = createLetterTreeNode(newLetter);
    }
    else if (newLetter < (*root)->letter) // the character is less than the actual root
    {
        if ((*root)->left == NULL) // go to the left
        {
            (*root)->left = createLetterTreeNode(newLetter);
        }
        else // keep on looking
        {
            insertLetterTreeNode(&((*root)->left), newLetter);
        }
    }
    else if (newLetter > (*root)->letter) // the character is greater than the actual root
    {
        if ((*root)->right == NULL) // go to the right
        {
            (*root)->right = createLetterTreeNode(newLetter);
        }
        else // keep on looking
        {
            insertLetterTreeNode(&((*root)->right), newLetter);
        }
    }
    else
    {
        (*root)->count->value++; // the character is the same as the root's character / increment count of letter in tree
    }
}

LetterTreeNode* searchLetterTreeNode(LetterTreeNode* root, char letter)
{
    if (root == NULL) // the root is null to begin with, what's the point
    {
        return NULL;
    }
    else if (root->letter == letter) // the root is the target
    {
        return root;
    }
    else if (root->letter < letter) // the target's letter comes after the root's letter
    {
        return searchLetterTreeNode(root->right, letter);
    }
    else if (root->letter > letter) // the target's letter comes before the root's letter
    {
        return searchLetterTreeNode(root->left, letter);
    }
}

LetterTreeNode* stringToLetterBinaryTree(char* str) // converts a string to a letter binary tree
{
    LetterTreeNode* root = NULL;
    if (str == NULL || *str == '\0') // check for empty/null string
    {
        return NULL;
    }
    while (*str != '\0') // continue until no characters
    {
        root = insertLetterTreeNode(root, *str); // insert every character into the letter binary tree
        *str++; // next character
    }
}

Count* searchLetterCount(LetterTreeNode* root, char letter)
{
    if (root == NULL) // if the root is null return a count of 0
    {
        return NULL;
    }
    LetterTreeNode* target = searchLetterTreeNode(root, letter);
    return target ? target->count : NULL; // may not find the letter
}


int main(void)
{
    printf("Hello, World!\n");
    LetterTreeNode *root = NULL;
    insertLetterTreeNode(&root, 'a');
    printf("Letter: %c\n", root->letter);
    printf("Count: %d\n", root->count->value);
    freeLetterTreeNode(root);
    return 0;
}
