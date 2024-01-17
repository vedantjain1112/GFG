class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        unordered_map<int, int> occurrences;

        for (int num : arr) {
            occurrences[num]++;
        }

        unordered_set<int> uniqueOccurrenceCounts;
        for (const auto& entry : occurrences) {
            if (!uniqueOccurrenceCounts.insert(entry.second).second) {
                return false;
            }
        }

        return true;
    }
};