class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<std::string> validSubsequences;
        validSubsequences.push_back("");

        for (const std::string& str : arr) {
            std::vector<std::string> currentSubsequences;
            for (const std::string& existing : validSubsequences) {
                std::string candidate = existing + str;
                std::unordered_set<char> uniqueChars(candidate.begin(), candidate.end());
                if (candidate.size() == uniqueChars.size()) {
                    currentSubsequences.push_back(candidate);
                }
            }
            validSubsequences.insert(validSubsequences.end(), currentSubsequences.begin(), currentSubsequences.end());
        }

        int maxLength = 0;
        for (const std::string& str : validSubsequences) {
            maxLength = std::max(maxLength, static_cast<int>(str.size()));
        }

        return maxLength;
    }
};