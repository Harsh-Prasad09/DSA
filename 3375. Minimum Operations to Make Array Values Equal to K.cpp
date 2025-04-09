class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for (int num: nums) {
            if (num < k) return -1;
            
            if (num == k) continue;

            st.insert(num);
        }

        return st.size();
    }
};
