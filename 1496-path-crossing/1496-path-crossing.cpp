class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> visited;
        visited.insert("0,0");

        for (char move : path) {
            switch (move) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }

            string currentPos = to_string(x) + "," + to_string(y);
            if (visited.find(currentPos) != visited.end()) {
                return true;
            }

            visited.insert(currentPos);
        }

        return false;
    }

};