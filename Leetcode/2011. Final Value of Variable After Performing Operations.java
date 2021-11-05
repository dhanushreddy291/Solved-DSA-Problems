class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int length = operations.length, Ans = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 3; j++) {
                if (operations[i].charAt(j) == '+') Ans++;
                else if (operations[i].charAt(j) == '-') Ans--;
            }
        }
        return Ans/2;
    }
}