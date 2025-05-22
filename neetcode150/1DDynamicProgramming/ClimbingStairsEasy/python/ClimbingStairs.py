class Solution:
    def climbStairsFirst(self, n: int) -> int: # brute force attempt, recognised fibonacci, ACCEPTED
        mem = [1, 2] # index 0, 1 mapped
        if n in mem: # base case
            return n
        firstIndex = True
        for _ in range(2, n): # iterate n - 2
            if firstIndex: # save to first index of mem
                mem[0] = mem[0] + mem[1]
            else: # save to second index of mem
                mem[1] = mem[0] + mem[1]
            firstIndex = not firstIndex # switch to other space
        if firstIndex: # return other index
            return mem[1]
        else:
            return mem[0]
    
    def climbStairsSecond(self, n: int) -> int: # optimised, ACCEPTED
        mem = [1, 2] # first two memorised
        if n in mem: # base case
            return n
        for i in range(2, n): # iterate n - 2
            mem[i % 2] = mem[0] + mem[1] # ditch oldest memory
        return mem[(n + 1) % 2] # return newest memory
