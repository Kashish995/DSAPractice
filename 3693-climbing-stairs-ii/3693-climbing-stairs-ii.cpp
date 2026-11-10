class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        int i = 1;
        do{
            int j = 1;
            do{
                dp[i] = min(dp[i], dp[i - j] + costs[i - 1] + (long long)j * j);
                j++;
            } while(j <= 3 && i - j >= 0);

            i++;

        } while (i <= n);

        return (int)dp[n];
    }
};