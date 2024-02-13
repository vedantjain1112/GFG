class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return ""; // Return empty string if no palindrome found
    }

private:
    bool isPalindrome(const string& word) {
        int left = 0;
        int right = word.length() - 1;
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};