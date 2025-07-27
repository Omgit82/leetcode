// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/?envType=daily-question&envId=2025-07-27


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // Step 1: Remove consecutive duplicates
        vector<int> clean;
        clean.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                clean.push_back(nums[i]);
            }
        }

        // Step 2: Count hills and valleys
        int count = 0;
        for (int i = 1; i < clean.size() - 1; i++) {
            if ((clean[i] > clean[i - 1] && clean[i] > clean[i + 1]) ||
                (clean[i] < clean[i - 1] && clean[i] < clean[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
