class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> duplicates;

        for (int num : nums) {
            int index = std::abs(num) - 1; 
            if (nums[index] < 0)
                duplicates.push_back(index + 1); 
            else
                nums[index] = -nums[index]; 
        }

        return duplicates;
    }
};