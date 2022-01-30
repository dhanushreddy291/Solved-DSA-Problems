class Solution {
    public boolean backspaceCompare(String s, String t) {
        Stack <Character> string1 = new Stack <Character>();
        Stack <Character> string2 = new Stack <Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '#') string1.push(s.charAt(i));
            else if (string1.size() != 0) string1.pop();
        }
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) != '#') string2.push(t.charAt(i));
            else if (string2.size() != 0) string2.pop();
        }
        while (string1.size() > 0 && string2.size() > 0) {
            char A = string1.pop(), B = string2.pop();
            if (A != B) return false;
        }
        return string1.size() == 0 && string2.size() == 0;
    }
}