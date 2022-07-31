class Trie {

private:
    bool wordEnd;
    Trie* Words[26];
	
public:
    Trie() {
        this -> wordEnd = false;
        for (int i = 0; i < 26; i++) {
            this -> Words[i] = NULL;
        }
    }
    
    void insert(string word) {
        Trie* Root = this;
        int N = word.size();
        for (int i = 0; i < N; i++) {
            if (Root -> Words[word[i] - 'a'] == NULL) {
                Root -> Words[word[i] - 'a'] = new Trie();
            }
            Root = Root -> Words[word[i] - 'a'];
        }
        Root -> wordEnd = true;
    }
    
    bool search(string word) {
        Trie* Root = this;
        int N = word.size();
        for (int i = 0; i < N; i++) {
            if (Root -> Words[word[i] - 'a'] == NULL) {
                return false;
            }
            Root = Root -> Words[word[i] - 'a'];
        }
        return Root -> wordEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* Root = this;
        int N = prefix.size();
        for (int i = 0; i < N; i++) {
            if (Root -> Words[prefix[i] - 'a'] == NULL) {
                return false;
            }
            Root = Root -> Words[prefix[i] - 'a'];
        }
        return true;
    }
};