class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack <Integer> Stack = new Stack<>();
        int N = temperatures.length;
        Stack.push(N - 1);
        int[] Answer = new int[N];
        Answer[N - 1] = 0;
        for (int i = N - 2; i > -1; i--) {
            while (Stack.size() > 0 && temperatures[i] >= temperatures[Stack.peek()]) {
                Stack.pop();
            }
            if (Stack.size() != 0) 
                Answer[i] = Stack.peek() - i;
            else 
                Answer[i] = 0;
            Stack.push(i);
        }
        return Answer;
    }
}