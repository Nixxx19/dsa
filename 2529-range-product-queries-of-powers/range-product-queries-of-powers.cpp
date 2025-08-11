class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int num, vector<vector<int>>& queryList) 
    {
        vector<int> powerList;
        
        
        for (int i = 0; i < 31; ++i) 
        {
            if ((num >> i) & 1) 
            {
                powerList.push_back(1 << i);
            }
        }

        vector<int> result;
        for (auto& query : queryList) 
        {
            int left = query[0], right = query[1];
            long long product = 1;
            for (int i = left; i <= right; ++i) 
            {
                product = (product * powerList[i]) % MOD;
            }
            result.push_back((int)product);
        }

        return result;
    }
};
