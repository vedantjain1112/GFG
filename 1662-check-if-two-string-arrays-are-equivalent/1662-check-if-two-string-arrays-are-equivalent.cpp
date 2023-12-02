class Solution {
public:
   bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string str1, str2;
    
    for (string w : word1) {
        str1 += w;
    }

    for (string w : word2) {
        str2 += w;
    }

    return str1 == str2;
}};