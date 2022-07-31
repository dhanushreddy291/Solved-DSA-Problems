class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        
        int N = words1.length, M = words2.length;
        int[] Freq = new int[26];
        List <String> universalSubsets = new ArrayList<>();

        for (int i = 0; i < M; i++) {

            int length = words2[i].length();
            int[] singleStringFreq = new int[26];

            for (int j = 0; j < length; j++) {
                singleStringFreq[words2[i].charAt(j) - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                Freq[j] = Math.max(Freq[j], singleStringFreq[j]);
            }
            
        }

        for (int i = 0; i < N; i++) {

            boolean universalSubset = true;
            int length = words1[i].length();
            int[] singleStringFreq = new int[26];

            for (int j = 0; j < length; j++) {
                singleStringFreq[words1[i].charAt(j) - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                if (singleStringFreq[j] < Freq[j]) {
                    universalSubset = false;
                    break;
                }
            }

            if (universalSubset) {
                universalSubsets.add(words1[i]);
            }

        }

        return universalSubsets;
    }
}