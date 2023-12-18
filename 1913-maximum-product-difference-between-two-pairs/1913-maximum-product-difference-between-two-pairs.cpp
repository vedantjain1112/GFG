class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int product1 = nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
        int product2 = nums[n - 1] * nums[n - 2] - nums[n - 3] * nums[n - 4];

        return max(product1, product2);
    }
};