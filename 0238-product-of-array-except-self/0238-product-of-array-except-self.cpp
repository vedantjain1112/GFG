class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixProducts(n, 1);
        vector<int> suffixProducts(n, 1);

        int prefixProduct = 1;
        for (int i = 0; i < n; ++i) {
            prefixProducts[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            suffixProducts[i] = suffixProduct;
            suffixProduct *= nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = prefixProducts[i] * suffixProducts[i];
        }

        return ans;
    }


    
};