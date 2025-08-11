class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        
        // Get powers of 2 from binary representation
        for (int i = 0; i < 31; ++i) {
            if ((n >> i) & 1) {
                powers.push_back(1 << i);
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long prod = 1;
            for (int i = l; i <= r; ++i) {
                prod = (prod * powers[i]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
