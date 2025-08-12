class Solution {
public:
    int numberOfWays(int target, int x) 
    {
        const int MOD = 1e9 + 7;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int base = 1; ; base++) 
        {
            long long power = 1; 
            for (int i = 0; i < x; i++) 
            {
                power *= base;
                if (power > target) break;
            }

            if (power > target) break;

            for (int sum = target; sum >= power; sum--)
            {
                dp[sum] = (dp[sum] + dp[sum - power]) % MOD;
            }
        }

        return dp[target];
    }
};
