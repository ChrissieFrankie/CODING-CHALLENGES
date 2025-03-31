class Solution:

    def contains_duplicate_one(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums)) # yeah less verbose than c++
