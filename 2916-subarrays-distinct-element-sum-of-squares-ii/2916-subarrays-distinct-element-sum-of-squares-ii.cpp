class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> s, sq, lz;

    void apply(int o, int l, int r, long long v) {
        long long len = r - l + 1;

        sq[o] = (sq[o] + 2 * v % MOD * s[o] + v * v % MOD * len) % MOD;
        s[o] = (s[o] + v * len) % MOD;
        lz[o] = (lz[o] + v)% MOD;
    }

    void push(int o, int l, int r) {
        if(lz[o]) {
            int m = (l + r) / 2;
            apply(2 * o, l, m, lz[o]);
            apply(2 * o + 1, m + 1, r, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            apply(o, l, r, 1);
            return;
             }
             push(o, l, r);
             int m = (l + r) / 2;
             if(ql <= m) update(2 * o, l, m, ql, qr);
             if(qr > m) update(2 * o + 1, m + 1, r, ql, qr);
             s[o] = (s[2 * o] + s[2 * o + 1]) % MOD;
             sq[o] = (sq[2 * o] + sq[2 * o + 1]) % MOD;

    }
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s.assign(4 * n, 0); sq = s; lz = s;

        vector<int> last(100001, -1);
        long long ans = 0;
        for(int j = 0; j < n; j++) {
            update(1, 0, n - 1, last[nums[j]] + 1, j);
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }
        return ans;
    }
};