class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_len: int = len(s)
        t_len: int = len(t)

        if s_len != t_len:
            return False

        s_dict = {}
        t_dict = {}

        for i in range(s_len):
            s_dict[s[i]] = s_dict.get(s[i], 0) + 1
            t_dict[t[i]] = t_dict.get(t[i], 0) + 1

        return s_dict == t_dict
