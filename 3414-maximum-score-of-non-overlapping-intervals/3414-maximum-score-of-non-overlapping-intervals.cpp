class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int, 4>> v(n);
        for(int  i = 0; i < n; i++) 
           v[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        sort(v.begin(), v.end());

        vector<int> lefts(n);
        for(int i = 0; i < n; i++) lefts[i] = v[i][0];

        using State = pair<long long, vector<int>>;
        vector<vector<State>> dp(n + 1, vector<State>(5, {0, {}}));

        for(int i = n - 1; i >= 0; i--) {
            int nxt = upper_bound(lefts.begin(), lefts.end(), v[i][1]) - lefts.begin();
            for(int k = 1; k <= 4; k++) {
                State best = dp[i + 1][k];
                State cand = dp[nxt][k - 1];
                cand.first += v[i][2];
                cand.second.push_back(v[i][3]);
                sort(cand.second.begin(), cand.second.end());
                if(cand.first > best.first || (cand.first == best.first&& cand.second < best.second))\
                best = cand;
                dp[i][k] = best;
            }
        }
        return dp[0][4].second;
    }
};