public class RemoveElement {
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

    public static void main(String[] args) {
        RemoveElement element = new RemoveElement();
        int count = element.removeElement(new int[]{3,2,2,3}, 3);
        System.out.println(count);
    }
}
