class Solution:
    def minCostClimbingStairsFirstAttempt(self, cost: List[int]) -> int: # Brute force attempt, WRONG ANSWER
        steps = [cost[0], cost[1]] # first two steps
        for i in range(2, len(cost)): # start from third step
            price = cost[i] # price of current step
            steps[i % 2] = min(price + steps[0], price + steps[1]) # min cost to reach current step
        return steps[len(cost) % 2]
    
    def minCostClimbingStairsSecondAttempt(self, cost: List[int]) -> int: # thinking about min, ACCEPTED
        steps = [cost[0], cost[1]] # first two steps
        for i in range(2, len(cost)): # start from third step
            price = cost[i] # price of current step
            steps[i % 2] = min(price + steps[0], price + steps[1]) # min cost to reach current step
        return min(steps[0], steps[1]) # return min cost of last two steps
    
    def minCostClimbingStairsThirdAttempt(self, cost: List[int]) -> int: # thinking about space complexity, ACCEPTED
        for i in range(2, len(cost)): # start from third step
            price = cost[i] # price of current step
            cost[i % 2] = min(price + cost[0], price + cost[1]) # min cost to reach current step
        return min(cost[0], cost[1]) # return min cost of last two steps

                

                
