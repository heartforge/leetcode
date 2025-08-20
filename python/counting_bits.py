class Solution:
    def countBits(self, n: int) -> List[int]:
        result: List[int] = []

        for i in range(n + 1):
            count = 0
            num = i
            while num:
                count = count + num % 2
                num >>= 1
            result.append(count)

        return result
