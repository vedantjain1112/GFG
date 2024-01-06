class Solution {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        int n = startTime.size();
        std::vector<std::tuple<int, int, int>> jobs;

        for (int i = 0; i < n; ++i) {
            jobs.push_back(std::make_tuple(endTime[i], startTime[i], profit[i]));
        }

        std::sort(jobs.begin(), jobs.end());

        std::vector<int> dp(n, 0);
        dp[0] = std::get<2>(jobs[0]);

        for (int i = 1; i < n; ++i) {
            int currProfit = std::get<2>(jobs[i]);
            int prevJobIdx = binarySearch(jobs, i);

            if (prevJobIdx != -1) {
                currProfit += dp[prevJobIdx];
            }

            dp[i] = std::max(currProfit, dp[i - 1]);
        }

        return dp[n - 1];
    }

private:
    int binarySearch(const std::vector<std::tuple<int, int, int>>& jobs, int index) {
        int low = 0, high = index - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (std::get<0>(jobs[mid]) <= std::get<1>(jobs[index])) {
                if (std::get<0>(jobs[mid + 1]) <= std::get<1>(jobs[index])) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};