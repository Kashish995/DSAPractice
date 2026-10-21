class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> idx;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool isNew = idx[val].empty();
        idx[val].insert(nums.size());
        nums.push_back(val);
        return isNew;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end() || it->second.empty()) return false;

        int i = *it->second.begin();      // any index holding val
        int lastPos = nums.size() - 1;
        int lastVal = nums[lastPos];

        it->second.erase(i);
        if (i != lastPos) {
            nums[i] = lastVal;            // move last element into the hole
            idx[lastVal].erase(lastPos);
            idx[lastVal].insert(i);
        }
        nums.pop_back();

        if (it->second.empty()) idx.erase(it);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};