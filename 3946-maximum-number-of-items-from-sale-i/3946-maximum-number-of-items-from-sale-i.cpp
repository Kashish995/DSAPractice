class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> cnt(n, 0);
        int cheapest = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
            if(items[j][0] % items[i][0] == 0) cnt[i]++;
            cheapest = min(cheapest, items[i][1]);
        }

        vector<int> f(budget + 1, 0);
        for(int i = 0; i < n; i++) {
            int price = items[i][1];
            for(int b = budget; b >= price; b--)
            f[b] = max(f[b], f[b - price] + cnt[i]);
        }
        int ans = 0;
        for(int s = 0; s <= budget;s++)
        ans = max(ans, f[s] + (budget - s) / cheapest);
        return ans;
    }
};