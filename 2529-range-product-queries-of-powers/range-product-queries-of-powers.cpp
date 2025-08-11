class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> exponents;

        for (int i = 0; i < 31; ++i) 
        {
            if ((n >> i) & 1) 
            {
                exponents.push_back(i);
            }
        }

        int sz = exponents.size();
        vector<int> prefixSum(sz);
        prefixSum[0] = exponents[0];
        for (int i = 1; i < sz; ++i) 
        {
            prefixSum[i] = prefixSum[i - 1] + exponents[i];
        }

        vector<int> ans;
        for (auto& q : queries) 
        {
            int l = q[0], r = q[1];
            int sumExp = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
            ans.push_back(modPow(2, sumExp, MOD));
        }

        return ans;
    }

    int modPow(int base, int exp, int mod) 
    {
        long long result = 1;
        long long b = base;
        while (exp > 0) 
        {
            if (exp % 2 == 1) result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }
};
