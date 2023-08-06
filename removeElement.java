class Solution {
    public int removeElement(int[] nums, int val) {
        int end = nums.length-1;
        for (int i = 0; i < nums.length; i++) {
            while (i <= end) {
                if (nums[i] == val) {
                    nums[i] = nums[end];
                    end--;
                } else {
                    break;
                }
            }
        }
        return end+1;
    }
}
