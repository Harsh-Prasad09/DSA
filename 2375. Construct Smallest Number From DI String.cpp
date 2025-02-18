class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        int cnt = 1;
        stack<char> st;

        string ans;

        for (int i = 0; i<n+1; i++) {
            st.push(cnt+'0');
            cnt++;

            if (i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
        }

        return ans;
    }
};
