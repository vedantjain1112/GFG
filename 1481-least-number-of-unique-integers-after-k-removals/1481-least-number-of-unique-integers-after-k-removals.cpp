class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        priority_queue<int, vector<int>, greater<int> > frequencies;
        for (auto it : map) {
            frequencies.push(it.second);
        }

        int elementsRemoved = 0;
    
        while (!frequencies.empty()) {
            elementsRemoved += frequencies.top();
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }
        return 0;
    }
};