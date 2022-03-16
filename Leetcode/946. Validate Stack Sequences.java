class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack <Integer> stack = new Stack<Integer>();
        int length = pushed.length, j = 0;
        for (int i = 0; i < length; i++) {
            while (!stack.empty() && stack.peek() == popped[j]) {
                j++;
                stack.pop();    
            }
            stack.push(pushed[i]);
        }
        while (!stack.empty() && stack.peek() == popped[j]) {
                j++;
                stack.pop();    
        }
        return stack.empty();
    }
}