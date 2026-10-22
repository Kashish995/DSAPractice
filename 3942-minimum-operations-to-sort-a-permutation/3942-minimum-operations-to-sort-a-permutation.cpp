class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool asc = true, desc = true;
        int s = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] != (s + i) % n) asc = false;
            if (nums[i] != ((s - i) % n + n) % n) desc = false;
        }
        int ans = INT_MAX;
        if (asc) {
            if (s == 0) return 0;
            ans = min(ans, min(n - s, s + 2));
        }
        if (desc) {
            int t = (s + 1) % n;
            ans = min(ans, min(t + 1, 1 + (n - t) % n));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};