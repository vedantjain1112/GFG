class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Initialize an array to store the maximum money that can be robbed up to the ith house
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Dynamic Programming to fill the dp array
        for (int i = 2; i < n; ++i) {
            // The maximum money that can be robbed up to the ith house is the maximum of either:
            // 1. The money robbed up to the (i-2)th house plus the money in the ith house
            // 2. The money robbed up to the (i-1)th house
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        // The final result is the maximum money that can be robbed up to the last house
        return dp[n - 1];
    }
};