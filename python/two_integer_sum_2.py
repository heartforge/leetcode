class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        result: List[int] = []
        l_ptr: int = 0
        r_ptr: int = len(numbers) - 1

        while l_ptr < r_ptr:
            calc = numbers[r_ptr] + numbers[l_ptr]
            if calc > target:
                r_ptr -= 1
            elif calc < target:
                l_ptr += 1
            else:
                l_ptr += 1
                r_ptr += 1
                result = [l_ptr, r_ptr]
                break

        return result
