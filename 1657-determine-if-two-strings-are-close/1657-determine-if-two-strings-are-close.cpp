class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        int w1[26] = {0};
        int w2[26] = {0};

        for (char c : word1) {
            w1[c - 'a']++;
        }

        for (char c : word2) {
            w2[c - 'a']++;
        }

        // Step 1:
        for (int i = 0; i < 26; i++) {
            if ((w1[i] == 0 && w2[i] != 0) || (w1[i] != 0 && w2[i] == 0)) {
                return false;
            }
        }

        // Step 2:
        unordered_map<int, int> map1, map2;

        for (int i = 0; i < 26; i++) {
            if (w1[i] > 0) {
                map1[w1[i]]++;
            }
            if (w2[i] > 0) {
                map2[w2[i]]++;
            }
        }

        return map1 == map2;
    }
};