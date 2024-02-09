class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        std::vector<int> result;

        if (nums.empty())
            return result;

        std::sort(nums.begin(), nums.end());

        std::vector<int> dp(nums.size(), 1);
        std::vector<int> prev(nums.size(), -1);

        int maxIndex = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex])
                maxIndex = i;
        }

        int currentIndex = maxIndex;
        while (currentIndex != -1) {
            result.push_back(nums[currentIndex]);
            currentIndex = prev[currentIndex];
        }

        return result;
    }
};