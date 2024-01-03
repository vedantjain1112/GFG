class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<int> ops;
        int num = 0;
        int result = 0;
        int sign = 1; // 1 for positive, -1 for negative

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= ops.top(); ops.pop();
                result += nums.top(); nums.pop();
            }
        }

        return result + sign * num;
    }
};