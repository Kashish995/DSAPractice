class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
        for (int i = 0; i < (int)nums.size(); i++) {
            long long x = nums[i];
            auto it = window.lower_bound(x - valueDiff);
            if (it != window.end() && *it <= x + valueDiff) return true;

            window.insert(x);
            if (i >= indexDiff) window.erase((long long)nums[i - indexDiff]);
        }
        return false;
    }
};