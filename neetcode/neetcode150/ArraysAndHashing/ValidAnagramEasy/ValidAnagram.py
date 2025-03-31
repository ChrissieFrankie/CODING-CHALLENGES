class Solution:
    def isAnagramOne(self, s: str, t: str) -> bool: # brute force attempt
        if len(s) != len(t): # no the same size, not anagram
            return False
        s_list = list(s) # list them for flexibility
        t_list = list(t)
        for s_char in s_list: # compare and contrast
            try:
                position = t_list.index(s_char) # use t as your tracker
                t_list.pop(position)
            except ValueError:
                return False
        return len(t_list) == 0 # none remaining anagram
    
    def isAnagramTwo(self, s: str, t: str) -> bool: # slick force attempt
        # create two avl trees / two red-black trees
        # use one tree as a tracker
        # once that tracker tree is empty we can say its an anagram
        pass

        