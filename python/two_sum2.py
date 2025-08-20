class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}

        for i in range(len(nums)):
            compliment = target - nums[i]

            if compliment in m:
                return [m[compliment], i]
            else:
                m[nums[i]] = i

        return []
