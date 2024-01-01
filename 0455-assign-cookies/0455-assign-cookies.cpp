class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentChildren = 0;
        int i = 0; // Index for greed factor
        int j = 0; // Index for cookie size

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                contentChildren++;
                i++;
            }
            j++;
        }

        return contentChildren;
    }
};