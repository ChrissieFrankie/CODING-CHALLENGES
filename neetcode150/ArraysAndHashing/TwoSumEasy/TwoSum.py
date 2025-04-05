class Solution:
    def twoSumOne(self, nums: List[int], target: int) -> List[int]: # brute force attempt
        numToIndex = {} # num to index
        for i, num in enumerate(nums): # iterate through index - num
            if (target-num) in numToIndex: # if the complement num is in dict
                return [numToIndex[target-num], i] # return the index of the complement and the current num
            else: # otherwise store the index of the current num
                numToIndex[num] = i
        return [] # return empty for no results