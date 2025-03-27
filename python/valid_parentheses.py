class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for c in s:
            if c == "{" or c == "(" or c == "[":
                stk.append(c)
            else:
                if len(stk) == 0:
                    return False
                if c == "}" and stk.pop() != "{":
                    return False
                elif c == ")" and stk.pop() != "(":
                    return False
                elif c == "]" and stk.pop() != "[":
                    return False
                else:
                    continue

        return len(stk) == 0
