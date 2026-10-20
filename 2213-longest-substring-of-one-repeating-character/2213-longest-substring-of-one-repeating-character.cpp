class Solution {
    vector<array<int,4>> t;
    string s;

    void pull(int o, int l, int r) {
        int m = (l + r) / 2;
        auto &L = t[2*o], &R = t[2*o + 1], &x = t[o];
        x[3] = L[3] + R[3];
        x[0] = L[0];
        x[1] = R[1];
        x[2] = max(L[2], R[2]);

        if(s[m] == s[ m + 1]) {
            if(L[0] == L[3] ) x[0] = L[3] + R[0];
            if(R[1] == R[3] ) x[1] = R[3] + L[1];
            x[2] = max(x[2], L[1] + R[0]);

        }
    }

    void build(int o, int l, int r) {
        if(l == r) {
        t[o] = {1, 1, 1, 1}; 
        return;
        }

        int m = (l + r) / 2;
        build(2*o, l, m);
        build(2*o+1, m + 1, r);
        pull(o, l, r);
    }

    void update(int o, int l, int r, int i) {
        if(l == r) return ;
        int m = (l  +r) / 2;
        if(i <= m) update(2*o, l, m, i);
        else update(2 * o + 1, m + 1, r, i);
        pull(o, l, r);
    }
public:
    vector<int> longestRepeating(string str, string queryCharacters, vector<int>& queryIndices) {
        s = str;
        int n = s.size();
        t.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> res;
        for(int q = 0; q < (int)queryIndices.size(); q++) {
            int idx = queryIndices[q];
            s[idx] = queryCharacters[q];
            update(1, 0, n - 1, idx);
            res.push_back(t[1][2]);
        }
        return res;
    }
};