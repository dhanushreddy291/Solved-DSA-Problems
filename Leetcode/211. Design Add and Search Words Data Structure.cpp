class WordDictionary {

private:
    WordDictionary* Head;
    bool endWord;
    WordDictionary* words[26];

public:
    WordDictionary() {
        this -> Head = NULL;
        this -> endWord = false;
        for (int i = 0; i < 26; i++) {
            this -> words[i] = NULL;
        }
    }
    
    void addWord(string word) {
        if (Head == NULL) {
            Head = new WordDictionary();
        }
        WordDictionary* Root = Head;
        int N = word.size();
        for (int i = 0; i < N; i++) {
            if (Root -> words[word[i] - 'a'] == NULL) {
                Root -> words[word[i] - 'a'] = new WordDictionary();
            }
            Root = Root -> words[word[i] - 'a'];
        }
        Root -> endWord = true;
    }

    bool helper(string &word, int i, int N, WordDictionary* Root) {
        if (Root == NULL) return false;
        if (i == N) return Root -> endWord;
        if (word[i] != '.') {
            if (Root -> words[word[i] - 'a'] == NULL) {
                return false;
            }
            return helper(word, i + 1, N, Root -> words[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (Root -> words[j] != NULL) {
                if (helper(word, i + 1, N, Root -> words[j])) {
                    return true;
                } 
            }
        }
        return false;  
    }
    
    bool search(string word) {
        if (Head == NULL) return false;
        return this -> helper(word, 0, word.size(), Head);
    }
};