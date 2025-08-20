class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0

        for i in range(32):
            op = (n >> i) & 1
            res += op << (31 - 1)
        return res
