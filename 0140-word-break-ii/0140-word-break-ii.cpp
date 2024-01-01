class Solution {
public:
       vector<string> wordBreakHelper(string s, unordered_set<string>& wordSet, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        vector<string> result;

        if (wordSet.count(s)) {
            result.push_back(s);
        }

        for (int i = 1; i < s.length(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix)) {
                string remaining = s.substr(i);
                auto remainingResult = wordBreakHelper(remaining, wordSet, memo);
                for (const string& sentence : remainingResult) {
                    result.push_back(prefix + " " + sentence);
                }
            }
        }

        memo[s] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return wordBreakHelper(s, wordSet, memo);
    }
};