class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

        // Base case: If k = 0, only one permutation is possible, which is the sorted array.
        for (int i = 1; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                if (j >= i)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};