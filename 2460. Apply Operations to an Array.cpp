class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        queue<int> qu;

        for (int i = 0; i<n; i++) {
            if (i == n-1) {
                qu.push(nums[i]);
                continue;
            } 

            if (nums[i] == nums[i+1] && nums[i] != 0) {
                qu.push(2*nums[i]);
                nums[i+1] = 0;
            }
            else if (nums[i] != nums[i+1] && nums[i] != 0) {
                qu.push(nums[i]);
            }
        }

        int idx = 0;
        nums.clear();
        nums.resize(n, 0);
        while(!qu.empty()) {
            nums[idx++] = qu.front();
            qu.pop();
        }

        return nums;
    }
};
