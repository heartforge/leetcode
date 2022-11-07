import java.util.ArrayDeque;
import java.util.Deque;
import java.util.NoSuchElementException;

class Solution {
    public boolean isValid(String s) {
        Deque<Integer> bracketStack = new ArrayDeque<>();
        Deque<Integer> sqBracketStack = new ArrayDeque<>();
        Deque<Integer> wavyBracketStack = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char bracket = s.charAt(i);

            try {
                if ('(' == bracket) {
                    bracketStack.push(0);
                } else if (')' == bracket) {
                    bracketStack.pop();
                } else if ('[' == bracket) {
                    sqBracketStack.push(0);
                } else if (']' == bracket) {
                    sqBracketStack.pop();
                } else if ('{' == bracket) {
                    wavyBracketStack.push(0);
                } else if ('}' == bracket) {
                    wavyBracketStack.pop();
                } else {
                    // Fail in case of invalid character
                    return false;
                }
            } catch (NoSuchElementException e) {
                // Fail in case of closed bracket before open bracket
                return false;
            }
        }

        if (bracketStack.isEmpty() && sqBracketStack.isEmpty() && wavyBracketStack.isEmpty()) {
            // Pass if all stacks are empty
            return true;
        } else {
            // Fail if not all stacks are empty
            return false;
        }
    }
}
