class Solution {

    string a, b;
    vector<vector<vector<char>>> memo;
public:
    bool go(int i, int j, int len) {
        char &m = memo[len][i][j];
        if (m) return m == 1;

        if(a.compare(i, len, b, j, len) == 0) {
            m = 1;
            return true;
        }

        int cnt[26] = {};

        for(int t = 0; t < len; t++) {
            cnt[a[i + t] - 'a']++;
            cnt[b[j + t] - 'a']--;
        }
        for(int c : cnt) if(c) {
            m = 2; 
            return false;

        }
        
        for(int k = 1; k < len; k++) {
            if((go(i, j, k) && go(i + k, j + k, len - k)) || (go(i, j + len - k, k) && go(i + k, j, len - k))) {
                m = 1;
                return true;
            }
        }
        m = 2;
        return false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        a = s1; b = s2;
        memo.assign(n + 1, vector<vector<char>>(n, vector<char>(n, 0)));
        return go(0, 0, n);    
    }
};