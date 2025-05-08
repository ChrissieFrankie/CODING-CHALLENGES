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

LetterTreeNode *searchLetterTreeNode(LetterTreeNode *root, char letter)
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

// LetterTreeNode *stringToLetterBinaryTree(char *str) // converts a string to a letter binary tree
// {
//     LetterTreeNode *root = NULL;
//     if (str == NULL || *str == '\0') // check for empty/null string
//     {
//         return NULL;
//     }
//     while (*str != '\0') // continue until no characters
//     {
//         insertLetterTreeNode(&root, *str); // insert every character into the letter binary tree
//         *str++;                                  // next character
//     }
// }

Count *searchLetterCount(LetterTreeNode *root, char letter)
{
    if (root == NULL) // if the root is null return a count of 0
    {
        return NULL;
    }
    LetterTreeNode *target = searchLetterTreeNode(root, letter);
    return target ? target->count : NULL; // may not find the letter
}

LetterTreeNode *findMinimumLetterTreeNode(LetterTreeNode *root) // finds the smallest node in a tree
{
    if (root == NULL) // the root is null
    {
        return NULL;
    }
    else if (root->left) // keep digging
    {
        return findMinimumLetterTreeNode(root->left);
    }
    else // we struck gold
    {
        return root;
    }
}

LetterTreeNode *deleteLetterTreeNode(LetterTreeNode **root, char letter)
{
    if (*root == NULL) // if the user tries to bluff
    {
        return NULL;
    }
    else if ((*root)->letter == letter) // root that matches
    {
        if ((*root)->left == NULL && (*root)->right == NULL) // no children to worry about
        {
            Count *rootCount = (*root)->count; // save the count of the root
            if (rootCount->value > 1)          // needs more than 1 deletion to remove
            {
                rootCount->value -= 1; // decrement value/count
                return *root;          // return same root/node
            }
            else // just needs one deletion to remove
            {
                freeLetterTreeNode(*root); // game over for root/node
                *root = NULL;              // safety first
                return NULL;
            }
        }
        else if ((*root)->left == NULL) // the right child to worry about
        {
            Count *rootCount = (*root)->count; // save the count of the root
            if (rootCount->value > 1)          // needs more than 1 deletion to remove
            {
                rootCount->value -= 1; // decrement value / count
                return *root;          // return same root/node
            }
            else // just needs one deletion to remove
            {
                LetterTreeNode *temp = *root; // save the target's pointer somewhere
                *root = (*root)->right;       // replace root with right pointer
                temp->right = NULL;           // prevent recursive freeing of right child
                freeLetterTreeNode(temp);     // free useless memory
                return *root;                 // return new root
            }
        }
        else if ((*root)->right == NULL) // the left child to worry about
        {
            Count *rootCount = (*root)->count; // needs more than 1 deletion to remove
            if (rootCount->value > 1)
            {
                rootCount->value -= 1; // decrement value / count
                return *root;          // return same root/node
            }
            else // just needs one deletion to remove
            {
                LetterTreeNode *temp = *root; // save the target's pointer somewhere
                *root = (*root)->left;        // replace root with left pointer
                temp->left = NULL;            // prevent recursive freeing of right child
                freeLetterTreeNode(temp);     // free useless memory
                return *root;                 // return new root
            }
        }
        else // two children to worry about
        {
            Count *rootCount = (*root)->count; // needs more than 1 deletion to remove
            if (rootCount->value > 1)
            {
                rootCount->value -= 1; // decrement value / count
                return *root;          // return some root/node
            }
            else
            {
                LetterTreeNode *successorNode = findMinimumLetterTreeNode((*root)->right); // we get the successor of the root
                if (successorNode)                                                         // the successor/child is still around
                {
                    (*root)->letter = successorNode->letter;                                       // just copy the letter
                    (*root)->count = successorNode->count;                                         // just copy the value
                    (*root)->right = deleteLetterTreeNode(&(*root)->right, successorNode->letter); // set the root to the modified subtree (without successor)
                } // what if the successorNode doesn't exist? **** ^-^ ******
                return *root; // relearning, will change this again
            }
        }
    }
    else if ((*root)->letter < letter) // look to the right
    {
        (*root)->right = deleteLetterTreeNode(&((*root)->right), letter); // updates the right subtree with modified subtree without the target node
        return *root;
    }
    else // look to the left
    {
        (*root)->left = deleteLetterTreeNode(&((*root)->left), letter); // updates the left subtree with modified subtree without the target node
        return *root;
    }
}

void printTreeInOrder(LetterTreeNode *root) // print the letter tree node characters in order
{
    if (root == NULL) // if null node return
    {
        return;
    }
    printTreeInOrder(root->left);
    printf("%c ", root->letter);
    printTreeInOrder(root->right);
}

int main(void)
{
    printf("Hello, World!\n");
    LetterTreeNode *root = NULL;
    insertLetterTreeNode(&root, 'e');
    insertLetterTreeNode(&root, 'a');
    insertLetterTreeNode(&root, 'b');
    insertLetterTreeNode(&root, 'c');
    insertLetterTreeNode(&root, 'd');
    insertLetterTreeNode(&root, 'f');
    insertLetterTreeNode(&root, 'g');
    insertLetterTreeNode(&root, 'h');
    insertLetterTreeNode(&root, 'i');
    printTreeInOrder(root);
    printf("\n");
    deleteLetterTreeNode(&root, 'e');
    printTreeInOrder(root);
    freeLetterTreeNode(root);
    return 0;
}
