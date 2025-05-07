class Solution:
    def twoSumTwo(self, numbers: List[int], target: int) -> List[int]: # this is my second attempt, first attempt idk what i was thinking, but the space is o(n)
        contacts = {}
        for i, num in enumerate(numbers):
            if target - num in contacts:
                return [contacts[target - num] + 1, i + 1]
            contacts[num] = i
            