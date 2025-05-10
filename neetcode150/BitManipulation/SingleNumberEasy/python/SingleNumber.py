class Solution:
    def singleNumberFirst(self, nums: List[int]) -> int: # brute force attempt without thinking
        nums_old = [] # visited nums
        while len(nums) > 0: # visit each num
            num = nums.pop(0) # visit num
            if num in nums or num in nums_old: # num is present again
                nums_old.append(num)
            else: # only present once
                return num
            
    def singleNumberSecond(self, nums: List[int]) -> int: # actually thinking about bit operations
        res = 0 # blank slate
        for num in nums: # iterate through nums
            res ^= num # same bit sequence negate, diff bit sequence lumps
        return res # singular num remaining