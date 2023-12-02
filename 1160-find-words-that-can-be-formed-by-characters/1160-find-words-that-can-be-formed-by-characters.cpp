class Solution {
public:
     int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charFreq;
        for (char c : chars) {
            charFreq[c]++;
        }

        int result = 0;

        for (string word : words) {
            unordered_map<char, int> wordFreq = charFreq;

            bool canFormWord = true;

            for (char c : word) {
                if (wordFreq.find(c) != wordFreq.end() && wordFreq[c] > 0) {
                    wordFreq[c]--;
                } else {
                    canFormWord = false;
                    break;
                }
            }

            if (canFormWord) {
                result += word.length();
            }
        }

        return result;
    }
};