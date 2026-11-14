class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = -1;

        for(int len = l; len <= r; len++) {
            for(int start = 0; start + len <= n; start++) {
                int sum = 0;
                for(int  k = start; k < start + len ; k++) {
                    sum += nums[k];

                }

                if(sum > 0) {
                    if(ans == -1 || sum < ans) {
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};