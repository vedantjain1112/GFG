class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumFreq;
        int prefixSum = 0;
        int count = 0;

        prefixSumFreq[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            count += prefixSumFreq[prefixSum - goal];
            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};