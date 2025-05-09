#include <stdio.h>
#include "BinaryTree.h"
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) // this doesn't pass the last two leetcode testcases
{
    if (strlen(s) != strlen(t))
        return false;
    LetterTreeNode* sBST = stringToLetterBinaryTree(s); // convert s to frequency bst
    int sLength = countTree(sBST); // count the s frequency bst 
    while (*t != '\0') // iterate through each char of t
    {
        deleteLetterTreeNode(&sBST, *t); // delete t from sBST
        int newLength = countTree(sBST); // count the s frequency bst after deletion
        if (newLength == sLength) // if the length remains the same
        {
            return false; // something doesn't match
        }
        sLength = newLength; // otherwise, the length decreased
        *t++;
    }
    int finalLength = countTree(sBST); // get the final length of s frequency bst
    return finalLength == 0; // anagram
}

int main(void)
{
    char* s = "anagram";
    char* t = "nagaram";
    bool result = isAnagram(s, t);
    printf("%s\n", result ? "true" : "false");
}