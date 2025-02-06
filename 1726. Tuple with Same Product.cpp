class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                int prod = nums[i] * nums[j];
                mpp[prod]++;
            }
        }

        int ans = 0;
        for (auto &[num, cnt]: mpp) {
            if (cnt > 1) {
                int permutations = cnt * (cnt-1) / 2;
                ans += (permutations*8);
            }
        }
        
        return ans;
    }
};
