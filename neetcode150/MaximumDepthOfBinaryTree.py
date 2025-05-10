# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def maxDepthFirst(self, root: Optional[TreeNode]) -> int: # first attempt doesn't work, just thinking of the word depth
        def getMaxDepth(root: Optional[TreeNode])->int: # nested function just because it would be cool
            if root and root.left: # root and left node exists
                return 1 + getMaxDepth(root.left) + getMaxDepth(root.right) # award depth point and look through each child
            elif root and root.right: # root and right node exists
                return 1 + getMaxDepth(root.left) + getMaxDepth(root.right) # award depth point and look through each child
            else: # root doesn't exist
                return 0
        res = 1 if root else 0 # if root exists award point
        return getMaxDepth(root) + res # above is completely unecessary

    def maxDepthSecond(self, root: Optional[TreeNode]) -> int: # second attempt, actually thinking depth means depth, and thinking of the word max
        if root: # root exists
            left_max = self.getMaxDepth(root.left) + 1 # look through left + award depth point
            right_max = self.getMaxDepth(root.right) + 1 # look through right + award depth point
            return (left_max if left_max > right_max else right_max) # return largest awarded branch
        else: # root doesn't exist
            return 0 # doesn't count
     
        