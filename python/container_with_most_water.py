class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l_ptr = 0
        r_ptr = len(heights) - 1
        curr_max = 0

        while l_ptr < r_ptr:
            distance = r_ptr - l_ptr
            area = min(heights[l_ptr], heights[r_ptr]) * distance

            if area > curr_max:
                curr_max = area
            if heights[l_ptr] >= heights[r_ptr]:
                r_ptr -= 1
            else:
                l_ptr += 1

        return curr_max
