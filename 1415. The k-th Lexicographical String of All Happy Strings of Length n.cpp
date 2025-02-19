class Solution {
public:
    void solve(int n, string &curr, int &cnt, int k, string &ans) {
        if (curr.length() == n) {
            cnt++;
            if (cnt == k) ans = curr;

            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) continue;
            
            curr.push_back(ch);
            solve(n, curr, cnt, k, ans);
            
            if (!ans.empty()) return;
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr;
        string ans;
        int cnt = 0;
        
        solve(n, curr, cnt, k, ans);

        return ans;
    }
};
