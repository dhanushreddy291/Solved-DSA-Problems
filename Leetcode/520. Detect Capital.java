class Solution {
    public boolean detectCapitalUse(String word) {
        boolean isFirstCharCapital = false, isAnyCharCapital = false, isAnyCharSmall = false;
        if (Character.isUpperCase(word.charAt(0))) isFirstCharCapital = true;
        else isAnyCharSmall = true;
        for (int i = 1; i < word.length(); i++) {
            if (Character.isUpperCase(word.charAt(i))) isAnyCharCapital = true;
            else isAnyCharSmall = true;
        }
        if (isFirstCharCapital) {
            if (isAnyCharCapital && isAnyCharSmall) return false;
            return true;
        } else return !isAnyCharCapital;
    }
}