class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        
        // While the person at position k hasn't finished buying tickets
        while (tickets[k] > 0) {
            // Each pass through the line
            for (int i = 0; i < n; ++i) {
                // If there are tickets left for person i
                if (tickets[i] > 0) {
                    // Reduce the number of tickets for person i by 1
                    tickets[i]--;
                    // Increase time taken
                    time++;
                    // If person k finished buying tickets, return time
                    if (i == k && tickets[k] == 0)
                        return time;
                }
            }
        }
        return time;
    }
};