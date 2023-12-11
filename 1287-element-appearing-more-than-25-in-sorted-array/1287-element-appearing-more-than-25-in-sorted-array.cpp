class Solution {
public:
   int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int targetFrequency = n / 4;

        for (int i = 0; i < n - targetFrequency; ++i) {
            if (arr[i] == arr[i + targetFrequency]) {
                return arr[i];
            }
        }


        return -1;
    }
};