# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Reverse half of the list
        second = slow.next
        prev = slow.next = None

        while second:
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp

        # Merge
        curr = head
        while prev:
            tmp1, tmp2 = curr.next, prev.next
            curr.next = prev
            prev.next = tmp1
            curr, prev = tmp1, tmp2
