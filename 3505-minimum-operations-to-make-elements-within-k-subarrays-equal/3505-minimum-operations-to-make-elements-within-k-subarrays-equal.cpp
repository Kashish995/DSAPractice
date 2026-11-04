class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> vals(nums);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();

        vector<int> id(n);
        for (int i = 0; i < n; i++)
            id[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;

        vector<long long> bc(m + 1, 0), bs(m + 1, 0);
        auto upd = [&](int i, int c, long long v) {
            for (; i <= m; i += i & -i) { bc[i] += c; bs[i] += v; }
        };
        auto qry = [&](int i) {
            long long c = 0, s = 0;
            for (; i > 0; i -= i & -i) { c += bc[i]; s += bs[i]; }
            return make_pair(c, s);
        };
        int LOG = 1;
        while ((LOG << 1) <= m) LOG <<= 1;
        auto kth = [&](long long kk) { // smallest index with prefix count >= kk
            int pos = 0;
            for (int pw = LOG; pw; pw >>= 1) {
                if (pos + pw <= m && bc[pos + pw] < kk) {
                    pos += pw;
                    kk -= bc[pos];
                }
            }
            return pos + 1;
        };

        int W = n - x + 1;
        vector<long long> cost(W);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            upd(id[i], 1, nums[i]);
            total += nums[i];
            if (i >= x) {
                upd(id[i - x], -1, -nums[i - x]);
                total -= nums[i - x];
            }
            if (i >= x - 1) {
                int idx = kth((x + 1) / 2);
                long long med = vals[idx - 1];
                auto [c, s] = qry(idx);
                cost[i - x + 1] = med * c - s + (total - s) - med * (x - c);
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] < INF)
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
            }
        }
        return dp[n][k];
    }
};