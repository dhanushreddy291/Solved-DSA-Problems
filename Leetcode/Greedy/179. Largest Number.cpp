class Solution {
  public:
    string largestNumber(vector < int > & nums) {
      vector < string > temp;
      for (int i = 0; i < nums.size(); i++) {
        temp.push_back(to_string(nums[i]));
      }
      sort(temp.begin(), temp.end(), [](string & s1, string & s2) {
        return s1 + s2 > s2 + s1;
      });
      for (int i = 1; i < temp.size(); i++) {
        temp[0] += temp[i];
      }
      return temp[0][0] == '0' ? "0" : temp[0];
    }
};