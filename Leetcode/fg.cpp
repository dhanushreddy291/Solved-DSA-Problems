class RandomizedSet {
private:
    unordered_map <int, int> Map;
    vector <int> Nums;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (Map.find(val) != Map.end())
            return false;
        else {
            Map[val] = Nums.size();
            Nums.emplace_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (Map.find(val) != Map.end()) {
            int Last = Nums.back();
            Map[Last] = Map[val];
            Nums[Map[val]] = Last;
            Nums.pop_back();
            Map.erase(val);
            return true;
        }
        else
        return false;
    }
    
    int getRandom() {
        return Nums[rand() % Nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */