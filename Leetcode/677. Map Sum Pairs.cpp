class MapSum {
    
private:
    MapSum* Words[26] = {};
    int Value;
    
public:
    MapSum() {
        this -> Value = 0;
    }
    
    void insert(string key, int val) {
        MapSum* Head = this;
        for (char &ch: key) {
            if (Head -> Words[ch - 'a'] == nullptr) {
                Head -> Words[ch - 'a'] = new MapSum();
            }
            Head = Head -> Words[ch - 'a'];
        }
        Head -> Value = val;
        return;
    }
    
    int sum(string prefix) {
        MapSum* Head = this;
        for (char &ch: prefix) {
            if (Head -> Words[ch - 'a'] == nullptr) {
                return 0;
            }
            Head = Head -> Words[ch - 'a'];
        }
        return DFS(Head);
    }

    int DFS(MapSum* Head) {
        if (Head == nullptr) return 0;
        int Ans = Head -> Value;
        for (int i = 0; i < 26; i++) {
            Ans += DFS(Head -> Words[i]);
        }
        return Ans;
    }

};