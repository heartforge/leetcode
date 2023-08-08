class CantEatLunch {
    // circle - 0
    // square - 1

    // food is on a STACK
    // students are in a QUEUE

    public int countStudents(int[] students, int[] sandwiches) {
        Queue studentQueue = toLinkedList(students);
        int top = 0;
        int deadlockCounter = 0;

        while (studentQueue.head != null) {
            ListNode student = studentQueue.dequeue();

            // Student does not like sandwich
            if (student.val != sandwiches[top]) {

                // Student returns back to queue and deadlock counter incremented
                studentQueue.enqueue(student);
                deadlockCounter++;

                if (deadlockCounter == students.length) {
                    break;
                }

                // Student is fed
            } else {
                top++;
                deadlockCounter = 0;
            }
        }

        return students.length - top;
    }

    public class ListNode {
        int val;
        ListNode prev;
        ListNode next;

        public ListNode (int val) {
            this.val = val;
        }

        public ListNode (int val, ListNode prev, ListNode next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }

    public class Queue {
        ListNode head = null;
        ListNode tail = null;

        public void enqueue(ListNode node) {
            if (head == null) {
                head = node;
                tail = node;
            } else {
                tail.next = node;
                tail.next.prev = tail;
                tail = node;
            }
        }

        public ListNode dequeue() {
            if (head == null) {
                return null;
            }

            ListNode curr = head;
            head = head.next;
            
            curr.next = null;
            curr.prev = null;
            return curr;
        }
    }

    public Queue toLinkedList(int[] arr) {
        Queue queue = new Queue();
        for (int val : arr) {
            queue.enqueue(new ListNode(val));
        }
        return queue;
    }

    public static void main(String[] args) {
        int[] students = {1, 1, 0, 0};
        int[] sandwiches = {0, 1, 0, 1};

        CantEatLunch sol = new CantEatLunch();
        int count = sol.countStudents(students, sandwiches);
        System.out.println(count);
    }
}
