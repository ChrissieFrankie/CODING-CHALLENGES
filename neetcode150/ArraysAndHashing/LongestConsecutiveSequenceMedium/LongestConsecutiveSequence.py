class Solution:
    def longestConsecutiveZero(self, nums: List[int]) -> int: # brute force attempt, only passes the two given test cases, DOESN'T PASS ALL TEST CASES
        max_count = 0
        for num in nums: # iterate through nums to find initial left bound
            if num - 1 not in nums: # left bound extreme found
                left_bound = num # left bound found
                count = 1 # counts as first
                while left_bound + 1 in nums: # while right extreme not found
                    left_bound += 1 # move left bound to right extreme
                    count += 1 # increase count
                max_count = max_count if max_count > count else count # keep the greatest
        return max_count

    def longestConsecutiveOne(self, nums: List[int]) -> int: # optimised attempt, passes all test cases
        nums = set(nums) # avoid duplicates beat runtime
        max_count = 0
        for num in nums: # iterate through nums to find initial left bound
            if num - 1 not in nums: # left bound extreme found
                left_bound = num # left bound found
                count = 1 # counts as first
                while left_bound + 1 in nums: # while right extreme not found
                    left_bound += 1 # move left bound to right extreme
                    count += 1 # increase count
                max_count = max(max_count, count) # pythonic
        return max_count

        