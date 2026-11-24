class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        const int LIMIT = 2520 * 10;

        for(int  i = 0; i < n; i++) {
            int prod = 1, g = 0, l = 1;
            for(int j = i; j < n; j++) {
                prod *= nums[j];
                if(prod > LIMIT) break;
                g = __gcd(g, nums[j]);
                l = l / __gcd(l, nums[j]) * nums[j];
                if(prod == g * l) 
                ans = max(ans, j - i + 1);

            }
        }
        return ans;
    }
};