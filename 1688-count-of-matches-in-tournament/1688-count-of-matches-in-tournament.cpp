class Solution {
public:
   int numberOfMatches(int n) {
        int matches = 0;

        while (n > 1) {
            if (n % 2 == 0) {
                // If even, each team gets paired
                matches += n / 2;
                n /= 2;
            } else {
                // If odd, one team advances, and the rest get paired
                matches += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }

        return matches;
    }
};