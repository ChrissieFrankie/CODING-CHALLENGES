from collections import defaultdict

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
    
    def isAnagramTwo(self, s: str, t: str) -> bool: # why allocate more memory for additional lists
        if len(s) != len(t): # not the same size, not anagram
            return False
        track = {} # track the characters
        for c in s: # populate the track
            if c in track:
                track[c] += 1
            else:
                track[c] = 1
        for c in t: # depopulate the track
            if c in track:
                count = track[c]
                if count < 1:
                    return False
                else:
                    track[c] -= 1        
        vals = [val for val in track.values() if val > 0] # save excess
        return (len(vals) == 0) # is clear of excess, is anagram

    def isAnagramThree(self, s: str, t: str) -> bool: # why not have a dict with default values of 0
        if len(s) != len(t): # not the same size, not an anagram
            return False
        track = defaultdict(int) # dict that defaults to 0
        for c in s:
            track[c] += 1 # increment right away
        for c in t:
            track[c] -= 1 # decrement right away       
        return all(val == 0 for val in track.values()) # all values are 0