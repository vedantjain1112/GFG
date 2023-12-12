class Solution {
public:
  int maxProduct(std::vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};