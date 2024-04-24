class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int T0 = 0, T1 = 1, T2 = 1, T3;
        
        for (int i = 3; i <= n; ++i) {
            T3 = T0 + T1 + T2;
            T0 = T1;
            T1 = T2;
            T2 = T3;
        }
        
        return T2;
    }
}; 