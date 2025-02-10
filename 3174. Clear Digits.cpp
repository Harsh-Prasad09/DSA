class Solution {
public:
    string clearDigits(string s) {
        int idx = 0;
        int n = s.length();

        while(idx < n) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                s.erase(idx, 1);

                if (idx > 0) {
                    s.erase(idx - 1, 1);
                    idx--;
                }
            }
            else idx++;
        }

        return s;
    }
};
