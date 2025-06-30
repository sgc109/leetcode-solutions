class Solution:
    def __init__(self):
        self.hset = set()
        
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            ans ^= num
        return ans