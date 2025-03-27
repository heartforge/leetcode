import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        best_rate: int = max(piles)

        l, r = 1, best_rate

        while l <= r:
            m = (l + r) // 2
            time_elapsed = 0

            for pile in piles:
                time_elapsed += math.ceil(pile / m)
            print(time_elapsed)

            if h >= time_elapsed:
                best_rate = min(best_rate, m)
                print(best_rate)
                r = m - 1
            else:
                l = m + 1
        return best_rate
