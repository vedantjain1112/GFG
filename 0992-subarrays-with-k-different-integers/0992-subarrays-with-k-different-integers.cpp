class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
private:
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> frequency;
        int distinctCount = 0;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < n; ++right) {
            if (frequency[nums[right]] == 0) {
                distinctCount++;
            }
            frequency[nums[right]]++;
            
            while (distinctCount > k) {
                frequency[nums[left]]--;
                if (frequency[nums[left]] == 0) {
                    distinctCount--;
                }
                left++;
            }
            result += right - left + 1;
        }
        
        return result;
    }
};