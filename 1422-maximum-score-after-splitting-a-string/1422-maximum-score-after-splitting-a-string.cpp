class Solution {
public:
   int maxScore(string s) {
        int maxScore = 0;
        int zerosLeft = 0, onesRight = 0;

        // Count total number of ones in the string
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') {
                totalOnes++;
            }
        }

        // Iterate through the string, excluding the last character
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                zerosLeft++;
            } else {
                onesRight++;
            }

            // Calculate the score for the current split
            int currentScore = zerosLeft + (totalOnes - onesRight);
            // Update maxScore if the current score is greater
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};