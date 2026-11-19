class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int removeTwoSmallest = nums[n - 1] - nums[2];
        int removeTwoLargest = nums[n - 3] - nums[0];
        int removeOneEach = nums[n - 2] - nums[1];

        return min({removeTwoSmallest, removeTwoLargest, removeOneEach});
    }
};