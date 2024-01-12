class Solution {
public:
    bool halvesAreAlike(std::string s) {
        // Define a set of vowels for efficient lookup
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        // Calculate the length of the string
        int length = s.length();
        
        // Initialize counts for vowels in the first and second halves
        int countA = 0, countB = 0;
        
        // Iterate through the first half of the string
        for (int i = 0; i < length / 2; ++i) {
            // Check if the character is a vowel
            if (vowels.find(s[i]) != vowels.end()) {
                // Increment the count for the first half
                countA++;
            }
        }
        
        // Iterate through the second half of the string
        for (int i = length / 2; i < length; ++i) {
            // Check if the character is a vowel
            if (vowels.find(s[i]) != vowels.end()) {
                // Increment the count for the second half
                countB++;
            }
        }
        
        // Return true if the counts for both halves are equal, otherwise return false
        return countA == countB;
    }
};