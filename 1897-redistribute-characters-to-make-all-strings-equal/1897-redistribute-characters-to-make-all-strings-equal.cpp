class Solution {
public:
   bool makeEqual(vector<string>& words) {
        unordered_map<char, int> charCount;

        for (const string& word : words) {
            for (char ch : word) {
                charCount[ch]++;
            }
        }

        for (const auto& it : charCount) {
            if (it.second % words.size() != 0) {
                return false;
            }
        }

        return true;
    }

};