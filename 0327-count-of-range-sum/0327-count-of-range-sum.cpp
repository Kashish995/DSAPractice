class Solution {
private:
    int countWhileMergeSort(vector<long long>& sums, int start, int end, int lower, int upper) {
        if(end - start <= 1) return 0;

        int mid = start + (end - start ) /2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) + 
                    countWhileMergeSort(sums, mid, end, lower, upper);

        int l = mid, r = mid;
        int j = mid, k = mid;

        for(int i = start; i < mid; i++) {
            while(l < end && sums[l] - sums[i] < lower) l++;
            while(r < end && sums[r] - sums[i] <= upper) r++;
            count += (r - l);
        }
        vector<long long> temp;
        temp.reserve(end - start);
        int p1 = start, p2 = mid;

        while(p1 < mid && p2 < end) {
            if(sums[p1] <= sums[p2]) {
                temp.push_back(sums[p1++]);
            }else{
                temp.push_back(sums[p2++]);
            }
        }
        while(p1 < mid) temp.push_back(sums[p1++]);
        while(p1 < mid) temp.push_back(sums[p1++]);

        for(int i = 0; i < temp.size(); ++i) {
            sums[start + i] = temp[i];
        }
        return count;
}
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countWhileMergeSort(sums, 0, n + 1, lower, upper);
    }
};