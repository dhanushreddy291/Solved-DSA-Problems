/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector <int> nestedList;
    int index;
    void helper(NestedInteger &NestedElement) {
        if (NestedElement.isInteger()) {
            nestedList.push_back(NestedElement.getInteger());
        } else {
            for (auto &elem: NestedElement.getList()) {
                helper(elem);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        for (auto &NestedElement: nestedList) {
            helper(NestedElement);
        }
    }
    
    int next() {
        return nestedList[index++];
    }
    
    bool hasNext() {
        return index < nestedList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */