class Solution {
public:
   int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> charIndex;
        int maxLen = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (charIndex.find(s[i]) != charIndex.end()) {
                maxLen = std::max(maxLen, i - charIndex[s[i]] - 1);
            } else {
                charIndex[s[i]] = i;
            }
        }

        return maxLen;
    }
};