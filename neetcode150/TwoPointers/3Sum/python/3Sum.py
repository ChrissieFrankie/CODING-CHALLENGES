class Solution:
    def threeSumFirst(self, nums: List[int]) -> List[List[int]]: # burte force attempt, TIME LIMIT EXCEEDED o(n^3)
        res = set() # create set to avoid duplicates
        n = len(nums) # length of nums
        
        for i in range(n): # iterate through each element
            for j in range(i + 1, n): # iterate through each element after i
                for k in range(j + 1, n): # iterate through each element after j
                    if nums[i] + nums[j] + nums[k] == 0: # check if the sum is zero
                        triplet = tuple(sorted([nums[i], nums[j], nums[k]])) # sort the triplet
                        res.add(triplet) # add to set to avoid duplicates
        return [list(triplet) for triplet in res] # convert each tuple back to list

    # i need to reduce the runtime, idk how to do it yet
    def threeSumSecond(self, nums: List[int]) -> List[List[int]]: # thought about binary search, ACCEPTED o(n log(n)) + o(n^2) = o(n^2) 
        n = len(nums) # length of nums
        nums.sort() # sorted nums o(n log(n)) = timsort sort
        res = [] # result list of triplets

        for i in range(n - 2): # iterate through indices o(n^2) two nested loops
            if i > 0 and nums[i] == nums[i - 1]: # the new becomes the old, skip duplicates
                continue
            left, right = i + 1, n - 1 # save the close and farthest friend
            while left < right: # make sure your friends don't get on top of each other, ^-^
                current_total = nums[i] + nums[left] + nums[right] # get current total
                if current_total == 0: # the three musketeers! meant for one another!
                    res.append([nums[i], nums[left], nums[right]]) # welcome to the club!
                    left += 1 # reduce the contestants
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]: # ignore repeats
                        left += 1
                    while left < right and nums[right] == nums[right + 1]: # ignore repeats
                        right -= 1
                else:
                    if current_total < 0: # sum too smqll
                        left += 1
                    else: # sum too large
                        right -= 1
        return res # return the club members





