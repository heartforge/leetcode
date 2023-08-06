import java.util.ArrayDeque;
import java.util.Deque;
import java.util.NoSuchElementException;

class Solution {
    public boolean isValid(String s) {
        Deque<Integer> bracketStack = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char bracket = s.charAt(i);

            try {
                if ('(' == bracket) {
                    bracketStack.push(0);
                } else if (')' == bracket) {
                    if (bracketStack.peek() == 0) {
                        bracketStack.pop();
                    } else {
                        return false;
                    }
                } else if ('[' == bracket) {
                    bracketStack.push(1);
                } else if (']' == bracket) {
                    if (bracketStack.peek() == 1) {
                        bracketStack.pop();
                    } else {
                        return false;
                    }
                } else if ('{' == bracket) {
                    bracketStack.push(2);
                } else if ('}' == bracket) {
                    if (bracketStack.peek() == 2) {
                        bracketStack.pop();
                    } else {
                        return false;
                    }
                } else {
                    // Fail in case of invalid character
                    return false;
                }
            } catch (Exception e) {
                // Fail in case of closed bracket before open bracket
                return false;
            }
        }

        if (bracketStack.isEmpty()) {
            // Pass if stack is empty
            return true;
        } else {
            // Fail if stack is not empty
            return false;
        }
    }
}
