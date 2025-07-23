class Solution {
    int solve(string &s, string &target, int x){
        int ans = 0;
        stack<char> st;
        int n = s.length();

        for (int i = 0; i<n; i++){
            if (s[i] == target[1] && !st.empty() && st.top() == target[0]){
                ans += x;
                st.pop();
            }
            else st.push(s[i]);
        }

        s.clear();
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());
        return ans;
    }

public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        int n = s.size();

        string s1 = "ab";
        string s2 = "ba";

        if (y > x){
            swap(x, y);
            swap(s1, s2);
        }

        return solve(s, s1, x) + solve(s, s2, y);
    }
};
