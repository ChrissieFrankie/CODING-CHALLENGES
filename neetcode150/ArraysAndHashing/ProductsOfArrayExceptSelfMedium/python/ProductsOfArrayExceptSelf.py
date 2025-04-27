class Solution:

    def productExceptSelfOne(self, nums: List[int]) -> List[int]: # brute force solution
        def product(nums, indices):
            product = nums[indices[0]] # start result as first num
            for i in indices[1:]: # iterate through rest of nums
                product *= nums[i] # use rest of nums as factors
            return product
        
        indices = list(range(len(nums))) # get list of indices
        res = [] # start result
        for i in indices: # iterate through indices
            indices_copy = indices.copy() # copy indices
            indices_copy.pop(i) # remove self
            res.append(product(nums, indices_copy)) # add product except self
        return res # return array products except self


                
        