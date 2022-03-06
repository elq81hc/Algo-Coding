# Definition for a binary tree node.
from asyncio.windows_events import NULL
import queue


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def averageOfLevels(self, root):
        if not root:
            return []
        ans = []
        q = queue.Queue()
        q.put(root)
        while not q.empty():
            size = q.qsize()
            avg = 0.0
            for i in range(size):
                top = q.get()
                avg += top.val
                if top.left:
                    q.put(top.left)
                if top.right:
                    q.put(top.right)
            avg /= size
            ans.append(avg)
        return ans
