class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // Using set to store values within the range

        for (int i = 0; i < nums.size(); ++i) {
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]); // Remove the element that's out of range
            }

            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            if (it != window.end() && *it - nums[i] <= valueDiff) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};
