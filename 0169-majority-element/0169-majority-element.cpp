class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        } 

        for(auto& pair : mp){
            if(pair.second > nums.size() / 2){
                return pair.first;
            }
        }

        return -1;
    }
};