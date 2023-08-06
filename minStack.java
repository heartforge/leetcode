import java.util.ArrayDeque;
import java.util.Deque;

class MinStack {
    // private List<Integer> stack = new ArrayList<>();
    private Deque<Integer> stack = new ArrayDeque<>();
    private Deque<Integer> minStack = new ArrayDeque<>();

    public MinStack() {
        
    }
    
    public void push(int val) {
        // Check if val is first element or less than existing min val
        if (minStack.peek() == null || minStack.peek() >= val) {
            minStack.push(val);
        }
        stack.push(val);
    }
    
    public void pop() {
        // Check if min stack is empty and if the val being popped is the same as the one in the stack
        if (minStack.peek().equals(stack.peek())) {
            minStack.pop();
        }
        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */