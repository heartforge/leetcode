class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count_map = {}
        freq = [[] for i in range(len(nums) + 1)]

        for num in nums:
            count_map[num] = count_map.get(num, 0) + 1

        for key, v in count_map.items():
            freq[v].append(key)

        res = []
        for i in range(len(freq) - 1, 0, -1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res
