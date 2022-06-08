class Solution {
    public int removePalindromeSub(String S) {
        if (S.length() == 0) return 0;
        else {
            for (int i = 0; i < S.length()/2; i++) {
                if (S.charAt(i) != S.charAt(S.length() - i - 1)) return 2;
            }
            
            return 1;
        }
    }
}