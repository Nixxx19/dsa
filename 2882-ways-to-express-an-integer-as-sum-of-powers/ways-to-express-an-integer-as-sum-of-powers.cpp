class Solution {
public:
    int numberOfWays(int target, int power) 
    {
        const int MOD = 1e9 + 7;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int base = 1; ; base++) {
            long long currPower = 1;
            for (int i = 0; i < power; i++) 
            {
                currPower *= base;
                if (currPower > target) break;
            }

            if (currPower > target) break;

            for (int sum = target; sum >= currPower; sum--) 
            {
                dp[sum] = (dp[sum] + dp[sum - currPower]) % MOD;
            }
        }

        return dp[target];
    }
};
