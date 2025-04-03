class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        max_len = 0
        l = 0
        most_freq = 0

        for r in range(len(s)):

            count[s[r]] = count.get(s[r], 0) + 1
            most_freq = max(most_freq, count[s[r]])

            while (r - l + 1) - most_freq > k:
                count[s[l]] -= 1
                l += 1
            max_len = max(max_len, r - l + 1)

        return max_len
