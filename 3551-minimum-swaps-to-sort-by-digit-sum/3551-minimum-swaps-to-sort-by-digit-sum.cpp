class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
            int n = nums.size();
            auto ds = [](int x ) {
                int s = 0;
                while(x) {
                    s += x % 10; x /= 10;

                }
                return s ;
            };
            vector<array<int, 3>> v(n);
            for(int i = 0; i < n; i++) 
            v[i] = {
                ds(nums[i]), nums[i], i
                };
                sort(v.begin(), v.end());

                vector<bool> vis(n);
                int cycles = 0;
                for(int i = 0; i < n; i++) {
                    if(vis[i]) continue;
                    cycles++;
                    for(int j = i; !vis[j]; j = v[j][2] ) vis[j] = true;
                }
                return n - cycles;
            }
        
    
};