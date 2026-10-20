class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue;

            bool ok = true;
            int preMax = 0;

            for(int b = 0; b < n && ok; b += k) {
                 int cnt = 0, pos = -1;

                 for(int j = 0; j < k; j++) {
                    int i = b + j;
                    int nx = b + (j + 1) % k;
                    if(nums[i] > nums[nx]) {
                        cnt++;
                        pos = i;
                    }
                 }

                 if(cnt > 1) {
                    ok = false;
                    break;
                    
                 }

                 int mn, mx;
                 if(cnt == 0) {
                    mn = mx = nums[b];
                 } else {
                    int start = b + ((pos - b + 1) % k);
                    mn = nums[start];
                    mx = nums[pos];
                 }

                 if(mn < preMax) {
                    ok = false;
                    break;
                 }

                 preMax = mx;
            }
            if(ok) ans += k;
        }
        return ans;
    }
};