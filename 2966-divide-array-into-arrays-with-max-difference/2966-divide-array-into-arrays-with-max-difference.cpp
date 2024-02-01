class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;

        // Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Check if it is possible to divide the array into arrays of size 3
        if (n % 3 != 0) {
            return result; // Cannot divide into arrays of size 3
        }

        // Iterate through the sorted array to form arrays of size 3
        for (int i = 0; i < n; i += 3) {
            // Check the difference between consecutive elements in each array
            if (i + 2 < n && nums[i + 2] - nums[i] <= k) {
                result.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                return {}; // Cannot form arrays satisfying conditions
            }
        }

        return result;
    }
};