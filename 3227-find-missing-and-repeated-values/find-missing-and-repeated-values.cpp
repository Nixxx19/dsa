class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int total = n * n;
        vector<int> freq(total + 1, 0);

        for (const auto& row : grid) // Counting frequency of each number
        {
            for (int num : row) {
                freq[num]++;
            }
        }
        int repeated = 0, missing = 0;
        for (int i = 1; i <= total; ++i) 
        {
            if (freq[i] == 2) repeated = i;
            if (freq[i] == 0) missing = i;
        }
        return {repeated,missing}; // Whatever satisfies the condition
    }
};
