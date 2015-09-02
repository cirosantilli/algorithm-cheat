/*
https://leetcode.com/problems/valid-parentheses/
*/

import java.util.Deque;
import java.util.LinkedList;

public class WellNestedOpenClose {

    public static char close(char c) {
        switch (c) {
            case '(':
                return ')';
            case '[':
                return ']';
            case '{':
                return '}';
            default:
                throw new IllegalArgumentException(String.valueOf(c));
        }
    }

    public static boolean isValid(String s) {
        Deque<Character> stack = new LinkedList<>();
        int l = s.length();
        for (int i = 0; i < l; i++) {
            char c = s.charAt(i);
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stack.push(c);
                break;
                default:
                    if (stack.isEmpty() || c != close(stack.pop()))
                        return false;
                break;
            }
        }
        if (!stack.isEmpty())
            return false;
        return true;
    }

    /*
    By using a magic value for characters that don't close,
    we can reuse this on the main loop code.

    Another saner but less efficient possibility would be to return character / boolean pair,
    where the boolean indicates if the char can be closed.
    */
    public static char closeMagic(char c) {
        switch (c) {
            case '(':
                return ')';
            case '[':
                return ']';
            case '{':
                return '}';
        }
        return 0;
    }

    public static boolean isValidMagic(String s) {
        Deque<Character> stack = new LinkedList<>();
        int l = s.length();
        for (int i = 0; i < l; i++) {
            char c = s.charAt(i);
            if (closeMagic(c) != 0) {
                stack.push(c);
            } else {
                if (stack.isEmpty() || c != closeMagic(stack.pop()))
                        return false;
            }
        }
        if (!stack.isEmpty())
            return false;
        return true;
    }

    public static void main(String[] args) {
        String stringsPass[] = {
            "",
            "()",
            "[]",
            "{}",
            "([])",
            "[()]",
        };
        for (String s : stringsPass) {
            assert isValid(s);
            assert isValidMagic(s);
        }

        String stringsFail[] = {
            "(",
            ")",
            "(]",
            "([)]",
        };
        for (String s : stringsFail) {
            assert !isValid(s);
            assert !isValidMagic(s);
        }
    }
}
