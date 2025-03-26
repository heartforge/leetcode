class Solution:
    def isPalindrome(self, s: str) -> bool:
        l_ptr: int = 0
        r_ptr: int = len(s) - 1

        while l_ptr < r_ptr:
            if not s[l_ptr].isalnum():
                l_ptr += 1
                continue
            if not s[r_ptr].isalnum():
                r_ptr -= 1
                continue
            if s[l_ptr].lower() != s[r_ptr].lower():
                return False
            else:
                l_ptr += 1
                r_ptr -= 1

        return True
