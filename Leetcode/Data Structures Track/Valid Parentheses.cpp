class Solution {
public:
    bool CanIPop (stack <char> &Stack, char c) {
        char t = Stack.top();
        return ((t == '(' && c == ')') || (t == '{' && c == '}') || (t == '[' && c == ']'));
    }
    bool isValid(string s) {
        stack <char> Stack;
        for (int i = 0; i < s.size(); i++) {
            if (Stack.empty()) Stack.push (s[i]);
            else {
                if (CanIPop (Stack, s[i])) Stack.pop();
                else Stack.push (s[i]);
            }
        }
        return Stack.empty();
    }
};