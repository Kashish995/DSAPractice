class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> divs(n + 1);
        for(int d = 1;d <= n; d++)
        for(int len = 2 * d; len <= n; len += d) 
        divs[len].push_back(d);

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        vector<int> row(n);

        for(int h = 0; h + 2 <= n; h++) {
            bool reachable = false;
            for(int c = 0; c < k; c++)
            if(dp[h][c] < INF) reachable = true;
            if(!reachable) continue;

            for(int j = h + 1; j < n; j++) {
                int len = j - h + 1, best = INF;
                for(int d : divs[len]) {
                    int changes = 0;
                    for(int r = 0; r < d && changes < best; r++) {
                        int lo = h + r, hi = h + r + (len / d - 1) * d;
                        while(lo < hi) {
                            if(s[lo] != s[hi]) changes++;
                            lo += d; hi -= d;
                        }
                    }
                    best = min(best, changes);
                    if(best == 0) break;
                }
                row[j] = best;
            }
            for(int j = h + 1; j < n; j++) {
                int p = j + 1;
                for(int c = 1; c <= k; c++)
                if(dp[h][c - 1] < INF)
                dp[p][c] = min(dp[p][c], dp[h][c-1] + row[j]);
            }
        }
        return dp[n][k];
    }
};