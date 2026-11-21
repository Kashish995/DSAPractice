class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for(int i = 1; i <n ; i++) g[parent[i]].push_back(i);

        vector<int> ans(n, 1);
        vector<int> newParent(n, -1);
        vector<int> saved(n, -1);
        vector<int> next(n, 0);
        int last[26];
        fill(last, last + 26, -1);

        vector<int> st;
        auto enter = [&](int v) {
            int c = s[v] - 'a';
            newParent[v] = (last[c] != -1) ? last[c] : parent[v];
            saved[v] = last[c];
            last[c] = v;
            st.push_back(v);
        };

        enter(0);
        while(!st.empty()) {
            int u = st.back();
            if(next[u] < (int)g[u].size()) {
                enter(g[u][next[u]++]);
            } else {
                last[s[u] - 'a' ] = saved[u];
                if(newParent[u] != -1) ans[newParent[u]] += ans[u];
                st.pop_back();
            }
        }
        return ans;
    }
};