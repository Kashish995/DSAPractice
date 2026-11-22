class Solution {
public:
    int longestDecomposition(string text) {
        int ans = 0; 
        int l = 0, r = text.size();

        while(l < r) {
            int len = 1;
            bool found = false;
            while(l + len <= r - len) {
                if(text.compare(l, len, text, r - len, len) == 0) {
                    found = true;
                    break;
                }
                len++;
            }
            if(found) {
                ans += 2;
                l += len;
                r -= len;
            } else {
                ans += 1;
                break;
            }
        }
        return ans;
    }
};