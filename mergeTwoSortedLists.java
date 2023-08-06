/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode curr1 = list1;
        ListNode curr2 = list2;
        ListNode mergedHead = null;
        ListNode mergedTail = null;

        if (curr1 == null && curr2 == null) {
            return mergedHead;
        } else if (curr1 == null && curr2 != null) {
            return list2;
        } else if (curr1 != null && curr2 == null) {
            return list1;
        }

        if (curr1.val <= curr2.val) {
            mergedHead = curr1;
            mergedTail = mergedHead;
            curr1 = curr1.next;
        } else {
            mergedHead = curr2;
            mergedTail = mergedHead;
            curr2 = curr2.next;
        }

        while (curr1 != null || curr2 != null) {

            if (curr1 != null && curr2 == null) {
                mergedTail.next = curr1;
                mergedTail = curr1;
                curr1 = curr1.next;
            } else if (curr1 == null && curr2 != null) {
                mergedTail.next = curr2;
                mergedTail = curr2;
                curr2 = curr2.next;
            } else if (curr1.val <= curr2.val) {
                mergedTail.next = curr1;
                mergedTail = curr1;
                curr1 = curr1.next;
            } else if (curr2.val < curr1.val) {
                mergedTail.next = curr2;
                mergedTail = curr2;
                curr2 = curr2.next;
            }
        }
        return mergedHead;
    }
}
