class Solution {
    public int numberOfSteps(int num) {
        int Steps = 0;
        while (num > 0) {
            if (num & 1) num >>= 1;
            else num--;
            Steps++;
        }
        return Steps;
    }
}