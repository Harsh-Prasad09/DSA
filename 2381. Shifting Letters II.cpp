class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n, 0);

        for (vector<int> &shift: shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = (shift[2] == 0)? -1: 1;

            diff[start] += dir;
            if (end + 1 < n) diff[end+1] -= dir;
        }

        for (int i = 1; i<n; i++) diff[i] += diff[i-1];
        
        for (int i = 0; i<n; i++) {
            diff[i] = diff[i] % 26;
            if (diff[i] < 0) diff[i] += 26;

            s[i] = ((s[i] - 'a') + diff[i]) % 26 + 'a';
        }

        return s;
    }
};
