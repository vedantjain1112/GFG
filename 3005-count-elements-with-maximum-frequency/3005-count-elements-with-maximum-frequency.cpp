class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        for (int num : nums) {
            frequencyMap[num]++;
        }

        int maxFrequency = 0;
        int maxFrequencyCount = 0;

        for (const auto& entry : frequencyMap) {
            maxFrequency = std::max(maxFrequency, entry.second);
        }

        for (const auto& entry : frequencyMap) {
            if (entry.second == maxFrequency) {
                maxFrequencyCount += entry.second;
            }
        }

        return maxFrequencyCount;
    }
};
