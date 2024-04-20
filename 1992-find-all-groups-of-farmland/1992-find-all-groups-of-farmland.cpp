class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    // Expand the group to the right
                    while (c2 + 1 < n && land[i][c2 + 1] == 1) ++c2;
                    // Expand the group downwards
                    while (r2 + 1 < m && land[r2 + 1][j] == 1) ++r2;
                    // Mark the group coordinates
                    result.push_back({r1, c1, r2, c2});
                    // Mark this group as visited
                    for (int x = r1; x <= r2; ++x) {
                        for (int y = c1; y <= c2; ++y) {
                            land[x][y] = 0;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};