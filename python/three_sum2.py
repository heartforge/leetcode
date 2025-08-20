class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        result: List[List[int]] = []

        for i in range(len(nums) - 2):
            l = i + 1
            r = len(nums) - 1
            target = nums[i] * (-1)

            while l < r:
                res = nums[l] + nums[r]
                if res > target:
                    r -= 1
                elif res < target:
                    l += 1
                else:
                    res_arr = [nums[l], nums[r], nums[i]]
                    if res_arr not in result:
                        result.append(res_arr)
                    l += 1
                    r -= 1
        return result
