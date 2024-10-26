class NeetCodeSolution:
    def hasDuplicateA(self, nums: List[int]) -> bool:
        prev = -1 #  remember the previous value
        for i in range(len(nums)): # iterates through the indices
            if nums[i] == prev: # compare with the previous value
                return True # duplicates
            prev = nums[i] # store the new previous value
        return False # no duplicate values
    
    # we iterate through the values instead of the indices
    def hasDuplicateB(self, nums: List[int]) -> bool:
        prev = -1 # remember the previous value
        for num in nums: # iterates through the elements
            if num == prev: # compare with the previous value
                return True # duplicates
            prev = num # store the new previous value
        return False # no duplicate values

    # why create a variable why allocate more memory when we're given allocated memory 
    def hasDuplicateC(self, nums: List[int]) -> bool:
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return True
            return False

    # the one liner
    def hasDuplicateD(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums)) # yeah

         