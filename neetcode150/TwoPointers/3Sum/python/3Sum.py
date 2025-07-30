class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]: # burte force attempt, TIME LIMIT EXCEEDED o(n^3)
        res = set() # create set to avoid duplicates
        n = len(nums) # length of nums
        
        for i in range(n): # iterate through each element
            for j in range(i + 1, n): # iterate through each element after i
                for k in range(j + 1, n): # iterate through each element after j
                    if nums[i] + nums[j] + nums[k] == 0: # check if the sum is zero
                        triplet = tuple(sorted([nums[i], nums[j], nums[k]])) # sort the triplet
                        res.add(triplet) # add to set to avoid duplicates
        return [list(triplet) for triplet in res] # convert each tuple back to list
