class Solution:
    def isHappyFirst(self, n: int) -> bool: # brute force attempt, didn't think about fat numbers, TIME LIMIT EXCEEDED
        i = n # start count
        while i > 0: # iterate until i runs out
            nums = [int(num) for num in str(n)] # get the nums of the num
            powers = [pow(num, 2) for num in nums if num != 0] # get the powers of the nums
            total = sum(powers) # get the total of the powers
            if total == 1: # happy
                return True
            else: # well
                n = total
            i -= 1
        return False # not happy
    
    def isHappySecond(self, n: int) -> bool: # thought about fat numbers, ACCEPTED
        i = n # start count
        while i > 0: # iterate until i runs out
            nums = [int(num) for num in str(n)] # get the nums of the num
            powers = [pow(num, 2) for num in nums if num != 0] # get the powers of the nums
            total = sum(powers) # get the total of the powers
            if total == 1: # happy
                return True
            n = total # well
            i /= 2
        return False
    
    def isHappyThird(self, n: int) -> bool: # thought about the number 2, ACCEPTED
        if n == 1: # base case
            return True
        for _ in range(ceil(log2(n)) + 2): # thought about the number 2
            nums = [int(num) for num in str(n)] # get the nums of the num
            powers = [pow(num, 2) for num in nums if num != 0] # get the powers of the nums
            total = sum(powers) # get the total of the powers
            if total == 1: # happy
                return True
            n = total # well
        return False
    
    # there has to be a better optimisation
            
        
            
        