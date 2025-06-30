# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> Tuple[bool, int]:
        if not root:
            return (True, 0)
        left: Tuple[bool, int] = self.dfs(root.left)
        if not left[0]:
            return (False, 0)
        right: Tuple[bool, int] = self.dfs(root.right)
        if not right[0]:
            return (False, 0)
        return (abs(left[1] - right[1]) <= 1, max(left[1], right[1]) + 1)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root)[0]