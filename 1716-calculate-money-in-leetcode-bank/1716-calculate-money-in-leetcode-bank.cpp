class Solution {
public:
    vector<int> generateOutput(int n) {
        vector<int> output;

        int deposit = 1;

        int newMon = 1;

        for (int i = 1; i <= n; ++i) {
            output.push_back(deposit);
            deposit += 1;
            if (i % 7 == 0) {
                newMon += 1;
                deposit = newMon;
            }
        }
        return output;
    }

    int totalMoney(int n) {
        vector<int> result = generateOutput(n);

        int total = 0;
        for (int amount : result) {
            total += amount;
        }
        return total;
    }
};