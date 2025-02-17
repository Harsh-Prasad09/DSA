class Solution {
public:
    void solve(vector<int> &freq, int &ans) {
        ans++;

        for (int i = 0; i<26; i++) {
            if (freq[i] == 0) continue;

            freq[i]--;
            solve(freq, ans);
            freq[i]++;
        }
    }
    
    int numTilePossibilities(string tiles) {
        int ans = 0;
        vector<int> freq(26, 0);

        for(char ch: tiles) {
            freq[ch-'A']++;
        }

        solve(freq, ans);

        return ans - 1;
    }
};
