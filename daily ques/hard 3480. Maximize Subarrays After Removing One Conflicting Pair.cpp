/// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/?envType=daily-question&envId=2025-07-27
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
         long validSubarrays = 0;
    int maxLeft = 0;
    int secondMaxLeft = 0;
    
    // restriction at index `i` is removed
    vector<long> gains(n + 1);
    // conflicts[r] := left endpoints that conflict with subarrays ending in r
    vector<vector<int>> conflicts(n + 1);

    for (const vector<int>& pair : conflictingPairs) {
      const int a = pair[0];
      const int b = pair[1];
      conflicts[max(a, b)].push_back(min(a, b));
    }

    for (int right = 1; right <= n; ++right) {
      for (const int left : conflicts[right]) {
        if (left > maxLeft) {
          secondMaxLeft = maxLeft;
          maxLeft = left;
        } else if (left > secondMaxLeft) {
          secondMaxLeft = left;
        }
      }
     
      validSubarrays += right - maxLeft;
      
      gains[maxLeft] += maxLeft - secondMaxLeft;
    }

    return validSubarrays + ranges::max(gains);
        
    }
};
