class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> indexes;
        const int n = deck.size();
        
        for (int i = 0; i < n; ++i)
            indexes.push(i);
        
        vector<int> result(n);
        
        for (int card : deck) {
            result[indexes.front()] = card;
            indexes.pop();
            if (!indexes.empty()) {
                indexes.push(indexes.front());
                indexes.pop();
            }
        }
        
        return result;
    }
};