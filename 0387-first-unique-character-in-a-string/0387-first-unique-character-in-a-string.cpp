class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> frequency;

        // Count the frequency of each character in the string
        for (char c : s) {
            frequency[c]++;
        }

        // Find the first unique character
        for (int i = 0; i < s.length(); ++i) {
            if (frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};