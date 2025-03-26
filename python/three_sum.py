class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result: List[List[int]] = []

        for i in range(0, len(nums) - 2):
            target: int = nums[i] * -1
            l_ptr: int = i + 1
            r_ptr: int = len(nums) - 1

            while l_ptr < r_ptr:
                calc = nums[l_ptr] + nums[r_ptr]
                if calc > target:
                    r_ptr -= 1
                elif calc < target:
                    l_ptr += 1
                else:
                    curr_res = [nums[i], nums[l_ptr], nums[r_ptr]]
                    if curr_res not in result:
                        result.append([nums[i], nums[l_ptr], nums[r_ptr]])
                    l_ptr += 1
                    r_ptr -= 1
        return result
