# while solving this leetcode i was listening to a series of videos about steve jobs' management style, skipping ads, and sipping captian morgan
class Solution:
    def maxProfitFirst(self, prices: List[int]) -> int: # doesn't pass all test cases
        leMin = prices[0]
        leMax = 0
        for price in prices[1:]:
            if price < leMin:
                leMin = price
                leMax = price
            if leMax != 0 and price > leMax:
                leMax = price
        return leMax - leMin
    
    def maxProfitSecond(self, prices: List[int]) -> int: # solved if max not found, doesn't pass all test cases
        leMin = prices[0]
        leMax = 0
        for price in prices[1:]:
            if price < leMin:
                leMin = price
                leMax = price
            if leMax != 0 and price > leMax:
                leMax = price
        if leMax == 0:
            return leMax
        return leMax - leMin
    
    def maxProfitThird(self, prices: List[int]) -> int: # thinking shallow, updated equal to less than/equal doesn't pass all test cases
        leMin = prices[0]
        leMax = 0
        for price in prices[1:]:
            if price <= leMin:
                leMin = price
                leMax = price
            if leMax != 0 and price > leMax:
                leMax = price
        if leMax == 0:
            return leMax
        return leMax - leMin
    
    def maxProfitFourth(self, prices: List[int]) -> int: # thinking shallow, added base case for only two prices, doesn't pass all test cases
        if len(prices) == 2:
            return max(prices[0], prices[1]) - min(prices[0], prices[1])
        leMin = prices[0]
        leMax = 0
        for price in prices[1:]:
            if price < leMin:
                leMin = price
                leMax = price
            if leMax != 0 and price > leMax:
                leMax = price
        if leMax == 0:
            return leMax
        return leMax - leMin
    
    def maxProfitFifth(self, prices: List[int]) -> int: # thinking shallow, updated base case, doesn't pass all test cases
        if len(prices) == 2 and prices[0] < prices[1]:
            return prices[1] - prices[0]
        leMin = prices[0]
        leMax = 0
        for price in prices[1:]:
            if price < leMin:
                leMin = price
                leMax = price
            if leMax != 0 and price > leMax:
                leMax = price
        if leMax == 0:
            return leMax
        return leMax - leMin
    
    def maxProfitSixth(self, prices: List[int]) -> int: # started all over, but didn't think different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < prices[min_i]:
                min_n = prices[i]
                min_i = i
                max_i = -1
                max_n = -1
            else:
                if prices[i] > prices[max_i]:
                    max_i = i
                    max_n = prices[max_i]
        if max_n == -1:
            return 0
        print(min_n, max_n)
        return max_n - min_n    

    def maxProfitSeventh(self, prices: List[int]) -> int: # just removed if, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < prices[min_i]:
                min_n = prices[i]
                min_i = i
                max_i = -1
                max_n = -1
            else:
                max_i = i
                max_n = prices[max_i]
        if max_n == -1:
            return 0
        print(min_n, max_n)
        return max_n - min_n    

    def maxProfitEigth(self, prices: List[int]) -> int: # readded if, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < prices[min_i]:
                min_n = prices[i]
                min_i = i
                max_i = -1
                max_n = -1
            else:
                if prices[i] > prices[max_i]:
                    max_i = i
                    max_n = prices[max_i]
        if max_n == -1:
            return 0
        print(min_n, max_n)
        return max_n - min_n    

    def maxProfitNinth(self, prices: List[int]) -> int: # updated if, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < prices[min_i]:
                min_n = prices[i]
                min_i = i
                max_i = -1
                max_n = -1
            else:
                if prices[i] > prices[max_i] and prices[i] > min_n:
                    max_i = i
                    max_n = prices[max_i]
        if max_n == -1:
            return 0
        print(min_n, max_n)
        return max_n - min_n    

    def maxProfitTenth(self, prices: List[int]) -> int: # basically updated else to the same if, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < prices[min_i]:
                min_n = prices[i]
                min_i = i
                max_i = -1
                max_n = -1
            elif prices[i] > max_i:
                max_i = i
                max_n = prices[max_i]
        if max_n == -1:
            return 0
        print(min_n, max_n)
        return max_n - min_n

    def maxProfitEleventh(self, prices: List[int]) -> int: # removed a few variable assignments, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < prices[min_i]:
                min_n = prices[i]
                min_i = i
            elif prices[i] > max_i:
                max_i = i
                max_n = prices[max_i]
        if max_n == -1:
            return 0
        print(min_n, max_n)
        return max_n - min_n   

    def maxProfitTwelth(self, prices: List[int]) -> int: # updated an if, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < min_n:
                min_n = prices[i]
                min_i = i
            elif prices[i] > max_i:
                max_i = i
                max_n = prices[max_i]
        if max_n == -1:
            return 0
        return max_n - min_n    
    
    def maxProfitThirteenth(self, prices: List[int]) -> int: # updated a variable assignment, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < min_n:
                min_n = prices[i]
                min_i = i
            elif prices[i] > max_i:
                max_i = i
                max_n = prices[i]
        if max_n == -1:
            return 0
        return max_n - min_n    
    

    def maxProfitFourteenth(self, prices: List[int]) -> int: # updated elif, not thinking different, doesn't pass all test cases
        min_i = 0
        min_n = prices[min_i]
        max_i = -1
        max_n = -1
        for i in range(1, len(prices)):
            print(min_n, max_n)
            if prices[i] < min_n:
                min_n = prices[i]
                min_i = i
            elif prices[i] > max_n:
                print(prices[i], max_i, '>')
                max_i = i
                max_n = prices[i]
        if max_n == -1:
            return 0
        return max_n - min_n    

    def maxProfitFifteenth(self, prices: List[int]) -> int: # started all over, thinking differently, passes all test cases
        le_petite = prices[0] # set the first as the min
        res = 0 # set the result as 0
        for i, n in enumerate(prices[1:]): # iterate through rest, use enumerate because it's cool (silly)
            if n < le_petite: # price is less than le petite
                le_petite = n # new le petite
                continue # skip to next iteration
            if le_petite < n: # current number is greater than le petite
                if n - le_petite > res: # difference is greater than result
                    res = n - le_petite # set result to the difference
        return res 

    def maxProfitSixteenth(self, prices: List[int]) -> int: # cut some fat, passes all test cases
        le_petite = prices[0]
        res = 0
        for n in prices:
            if n < le_petite:
                le_petite = n
                continue
            if n - le_petite > res:
                res = n - le_petite
        return res    

# end of story, don't sip on captain morgan while doing leetcode