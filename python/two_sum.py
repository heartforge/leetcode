class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}

        for i in range(len(nums)):
            compliment = target - nums[i]
            if compliment in dict:
                return [dict[compliment], i]
            else:
                dict[nums[i]] = i
        return [0, 0]
