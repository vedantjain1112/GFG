class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size();
        std::vector<int> left(n), right(n);
        std::stack<int> s1, s2;

        // Calculate left[i]: the distance to the nearest smaller element on the left
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[i] < arr[s1.top()]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // Calculate right[i]: the distance to the nearest smaller element on the right
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[i] <= arr[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        // Calculate the contribution of each element to the final sum
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return result;
    }
};