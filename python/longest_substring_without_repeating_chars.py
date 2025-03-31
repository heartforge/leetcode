class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        curr_res = {}
        l = 0
        longest_len = 0

        for r in range(len(s)):
            if s[r] in curr_res:
                l = max(curr_res[s[r]] + 1, l)

            curr_res[s[r]] = r
            longest_len = max(r - l + 1, longest_len)

        return longest_len
