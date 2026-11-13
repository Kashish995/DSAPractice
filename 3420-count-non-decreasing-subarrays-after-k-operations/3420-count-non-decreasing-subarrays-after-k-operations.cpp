class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), j = n - 1;
        long long ans = 0, cost = 0;
        deque<pair<int, int>> dq;

        for(int i = n - 1; i >= 0; i--) {
            int num = nums[i], cnt = 1;
            while(!dq.empty() && dq.back().first < num) {
                auto [v, c] = dq.back();
                dq.pop_back();
                cnt += c;
                cost += (long long)(num - v) * c;

            }
            dq.push_back({num, cnt});

            while(cost > k) {
                cost -= dq.front().first - nums[j];
                if(--dq.front().second == 0) dq.pop_front();
                j--;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};