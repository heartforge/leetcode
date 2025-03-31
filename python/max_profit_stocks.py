class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest: int = prices[0]
        max_profit: int = 0

        for price in prices:
            max_profit = max(max_profit, price - lowest)
            lowest = min(lowest, price)

        return max_profit
