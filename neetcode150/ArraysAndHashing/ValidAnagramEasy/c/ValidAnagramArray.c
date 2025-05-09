#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) 
{
    // don't reinvent the wheel / just use an array
    int slen = strlen(s); // get each length
    int tlen = strlen(t);
    if (slen != tlen) // compare lengths
    {
        return false;
    }
    int* tracker = (int*)(malloc(sizeof(int) * 26)); // create arr
    for (int i = 0; i < 26; i++) // initialise each element to 0
    { 
        tracker[i] = 0;
    }
    for (int i = 0; i < slen; i++) // iterate through s
    {
        tracker[s[i] - 'a'] += 1; // keep track of frequencies
    }
    for (int i = 0; i < tlen; i++) // iterate through t
    {
        tracker[t[i] - 'a'] -= 1; // mark off frequencies
    }
    for (int i = 0; i < 26; i++) // determine if not an anagram
    {
        if (tracker[i] != 0)
        {
            return false;
        }
    }
    return true; // is anagram
}

int main(void)
{
    char* s = "anagram";
    char* t = "nagaram";
    bool result = isAnagram(s, t);
    printf("%s\n", result ? "true" : "false");
}