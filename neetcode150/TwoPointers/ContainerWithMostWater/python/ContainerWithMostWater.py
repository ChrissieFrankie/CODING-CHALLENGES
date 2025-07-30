class Solution:
    def maxAreaFirst(self, height: List[int]) -> int: # brute force attempt, only passes 36 test cases o(n)
        n = len(height) # length of nums
        left, right = 0, n - 1 # start with largest container
        res = 0 # area result
        while left < right: 
            current_area = min(height[left], height[right]) * (right - left) # container area
            if current_area == res: # if current area is the same just reak
                break
            res = max(res, current_area) # container area
            if height[left] < height[left + 1]: # the next left is larger
                left += 1
            elif height[right] < height[right - 1]: # the right before is larger
                right -= 1
            else: # just go right
                right -= 1
        return res # return max area
    
    def maxAreaSecond(self, height: List[int]) -> int: # just move the lowest height position away from the edges ACCEPTED
        n = len(height) # length of nums
        left, right = 0, n - 1 # start with largest container
        max_area = 0 # area result
        while left < right: 
            current_area = min(height[left], height[right]) * (right - left) # container area
            max_area = max(max_area, current_area) # container area
            if height[left] <= height[right]: # move inward for the lowest height position
                left += 1
            else:
                right -= 1
        return max_area # return max area

