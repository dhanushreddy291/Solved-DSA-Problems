class Solution {
  public:
    vector < int > nextGreaterElement(vector < int > & nums1, vector < int > & nums2) {
      int N = nums2.size(), M = nums1.size();
      unordered_map < int, int > nextGreater = {{ nums2[N - 1], -1}};
      stack < int > Stack({ nums2[N - 1] });
      for (int i = N - 2; i >= 0; i--) {
        while (!Stack.empty() && Stack.top() <= nums2[i]) {
          Stack.pop();
        }
        nextGreater[nums2[i]] = (Stack.empty()) ? -1 : Stack.top();
        Stack.push(nums2[i]);
      }
      for (int i = 0; i < M; i++) nums1[i] = nextGreater[nums1[i]];
      return nums1;
    }
};