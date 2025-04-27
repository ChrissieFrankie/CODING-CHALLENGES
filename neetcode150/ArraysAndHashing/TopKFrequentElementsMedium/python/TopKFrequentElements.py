class Solution:
    def topKFrequentElementsOne(self, nums: List[int], k: int) -> List[int]: # brute force attempt
        frequency_table = {} # keep track of the frequency
        for num in nums: # iterate through the nums
            if num in frequency_table: # record the frequency
                frequency_table[num] += 1
            else:
                frequency_table[num] = 1
        frequency_table = dict(sorted(frequency_table.items(), key=lambda item: item[1], reverse=True)) # sort them based on value
        return list(frequency_table.keys())[:k] # return the first k keys