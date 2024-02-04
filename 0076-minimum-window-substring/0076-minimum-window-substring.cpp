class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for (char c : t) {
            target[c]++;
        }

        int left = 0, right = 0, minLen = INT_MAX, minLeft = 0, count = t.length();

        while (right < s.length()) {
            if (target.find(s[right]) != target.end() && target[s[right]] > 0) {
                count--;
            }
            target[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                if (target.find(s[left]) != target.end()) {
                    target[s[left]]++;
                    if (target[s[left]] > 0) {
                        count++;
                    }
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};