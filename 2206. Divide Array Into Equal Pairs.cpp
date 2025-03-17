class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num: nums) {
            mpp[num]++;
        }

        for (auto it: mpp) {
            int freq = it.second;
            if (freq % 2 == 1) return false;
        }
        return true;
    }
};
