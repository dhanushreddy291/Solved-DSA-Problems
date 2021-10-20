class Solution {
    public boolean areStringsIsomorphic(String s, String t) {
        int N = s.length();
        Map <Character, Character> Map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            if (Map.containsKey(s.charAt(i))) {
                if (Map.get(s.charAt(i)) != t.charAt(i))
                    return false;
            } else {
                Map.put(s.charAt(i), t.charAt(i));
            }
        }
        return true;
    }
    public boolean isIsomorphic(String s, String t) {
        return areStringsIsomorphic(s, t) && areStringsIsomorphic(t, s);
    }
}