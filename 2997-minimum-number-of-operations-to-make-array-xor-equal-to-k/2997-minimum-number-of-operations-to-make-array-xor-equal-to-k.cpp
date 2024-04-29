class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        int target = k ^ xorSum;
        
        int operations = 0;
        while (target) {
            target &= (target - 1);
            operations++;
        }
        
        return operations;
    }
};