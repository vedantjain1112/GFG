class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap; // Maps count to index
        int maxLength = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 0) ? -1 : 1;

            if (count == 0) {
                maxLength = i + 1;
            } else if (countMap.find(count) != countMap.end()) {
                maxLength = max(maxLength, i - countMap[count]);
            } else {
                countMap[count] = i;
            }
        }

        return maxLength;
    }
};