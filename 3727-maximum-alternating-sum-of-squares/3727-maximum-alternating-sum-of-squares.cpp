class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);

        for(int i = 0; i < n; i++) 
            a[i] = 1LL * nums[i] * nums[i];
            sort(a.begin(), a.end());

            long long sum = 0;
            int neg = n / 2;
            for(int i = 0; i < n; i++) {
                if(i < neg) sum -= a[i];
                else sum += a[i];
            }
            return sum;
        
    }
};