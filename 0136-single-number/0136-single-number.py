class Solution:
    def __init__(self):
        self.hset = set()
        
    def singleNumber(self, nums: List[int]) -> int:
        for num in nums:
            if num in self.hset:
                self.hset.remove(num)
            else:
                self.hset.add(num)
        return self.hset.pop()