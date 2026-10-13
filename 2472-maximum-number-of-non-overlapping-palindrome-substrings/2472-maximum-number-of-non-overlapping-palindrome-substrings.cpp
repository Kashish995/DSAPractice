class Solution {
public:
    bool pal(const string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;

        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size(), last = 0, count = 0;
        for(int i = 0; i < n; i++) {
            if(i - k + 1 >= last && pal(s, i - k + 1, i)) {
                count++;
                last = i + 1;
            }else if(i - k >= last && pal(s, i - k, i)) {
                count++;
                last = i + 1;
            }
        }
        return count;
    }
};