class Solution {
public:
  
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> charCount;
    for (char ch : s) {
        charCount[ch]++;
    }

    for (char ch : t) {
        if (charCount.find(ch) == charCount.end() || charCount[ch] == 0) {
            return false;
        }
        charCount[ch]--;
    }

    return true;
}

};