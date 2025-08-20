# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Deque


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        queue = Deque()
        if root:
            queue.append(root)

        level = 0

        while len(queue) > 0:
            for i in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level += 1

        return level
