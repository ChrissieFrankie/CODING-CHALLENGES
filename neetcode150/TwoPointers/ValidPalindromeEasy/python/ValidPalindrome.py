class Solution:
    def isPalindromeOne(self, s: str) -> bool:
        s = [ch.lower() for ch in s if ch.isalnum()] # s is now an arr of s with only alpha numeric characters
        if len(s) < 2: # if s has a single character or is blank it's automagically a palindrome
            return True
        slen = len(s) # len(s) called once
        for i in range((slen) // 2): # iterate through 50%** of the indices
            if s[i] != s[slen - i - 1]: # compare the char on the other side
                return False # they're not the same, s is not a palindrome
        return True # =^-^=