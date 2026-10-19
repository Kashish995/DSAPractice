class Solution {
public:
    int minCut(string s) {
        int  n = s.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++)dp[i] = i;

        auto expand = [&](int l , int r) {
            while(l >= 0 && r < n && s[l] == s[r]) {
                dp[r] = min(dp[r], l == 0 ? 0 : dp[l - 1] + 1);
                l--;
                r++;

            }
        };

        for(int i = 0 ; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return dp[n - 1];
    }
};