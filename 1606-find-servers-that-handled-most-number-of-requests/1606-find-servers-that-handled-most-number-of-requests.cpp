class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeSet;
        for(int i = 0; i < k; i++) freeSet.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        vector<int> cnt(k, 0);

        for(int i = 0; i < (int)arrival.size(); i++) {
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                freeSet.insert(busy.top().second);
                busy.pop();
            }
            if(freeSet.empty()) continue;

            auto it = freeSet.lower_bound(i % k);
            if(it == freeSet.end()) it = freeSet.begin();

            int s = *it;
            freeSet.erase(it);
            cnt[s]++;
            busy.push({arrival[i] + load[i], s});
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for(int i = 0; i < k; i++)
        if(cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};