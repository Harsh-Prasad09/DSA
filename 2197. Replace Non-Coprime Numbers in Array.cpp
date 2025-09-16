class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);

        int n = nums.size();
        for (int i = 1; i<n; i++) {
            int num = nums[i];

            while (!st.empty() && __gcd(st.top(), num) != 1) {
                num = lcm(st.top(), num);
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.emplace_back(st.top());
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};
