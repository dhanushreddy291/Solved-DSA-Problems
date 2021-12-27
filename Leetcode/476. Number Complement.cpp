class Solution {
    public int findComplement(int num) {
        int Pos = (int)(Math.log(num) / Math.log(2));
        for (int i = 0; i <= Pos; i++) 
            num ^= (1 << i);
        return num;
    }
}