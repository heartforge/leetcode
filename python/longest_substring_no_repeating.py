class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        curr_res = {}
        l = 0
        length = 0

        for r in range(len(s)):
            print(r)
            if s[r] in curr_res:
                l = max(curr_res[s[r]] + 1, l)

            curr_res[s[r]] = r
            length = max(r - l + 1, length)
        return length
