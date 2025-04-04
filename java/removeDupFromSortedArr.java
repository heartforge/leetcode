class Solution {
    public int removeDuplicates(int[] nums) {
        int currentIndex = 0;
        int compareIndex;
        for (compareIndex = currentIndex + 1; compareIndex < nums.length; compareIndex++) {
            if (nums[currentIndex] != nums[compareIndex]) {
                nums[++currentIndex] = nums[compareIndex];
            }
        }
        return currentIndex+1;
    }
}
