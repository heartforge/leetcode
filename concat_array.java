class Solution {
    public int[] getConcatenation(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            for (int num : nums) {
                ans.add(num);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
