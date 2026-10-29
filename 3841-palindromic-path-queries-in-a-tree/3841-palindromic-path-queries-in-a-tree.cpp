#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, LOG;
    vector<int> tin, tout, depth, bit, val;
    vector<vector<int>> up;

    void upd(int i, int d) { for (i++; i <= n + 1; i += i & -i) bit[i] ^= d; }
    int qry(int i) { int r = 0; for (i++; i > 0; i -= i & -i) r ^= bit[i]; return r; }
    void rangeXor(int l, int r, int d) { upd(l, d); upd(r + 1, d); }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) if (diff >> k & 1) a = up[k][a];
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--)
            if (up[k][a] != up[k][b]) a = up[k][a], b = up[k][b];
        return up[0][a];
    }

public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_;
        LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> g(n);
        for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }

        tin.assign(n, 0); tout.assign(n, 0); depth.assign(n, 0);
        bit.assign(n + 2, 0); val.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));
        for (int i = 0; i < n; i++) val[i] = 1 << (s[i] - 'a');

        // iterative DFS
        int timer = 0;
        vector<int> st = {0}, idx(n, 0);
        up[0][0] = 0;
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (idx[u] < (int)g[u].size()) {
                int v = g[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++) up[k][i] = up[k - 1][up[k - 1][i]];

        // build prefix XOR from root: add val[v] to subtree of v
        for (int i = 0; i < n; i++) rangeXor(tin[i], tout[i], val[i]);

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type; ss >> type;
            if (type == "update") {
                int x; char c; ss >> x >> c;
                int nv = 1 << (c - 'a');
                int d = val[x] ^ nv;
                if (d) rangeXor(tin[x], tout[x], d);
                val[x] = nv;
            } else {
                int u, v; ss >> u >> v;
                int l = lca(u, v);
                int mask = qry(tin[u]) ^ qry(tin[v]) ^ val[l];
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};