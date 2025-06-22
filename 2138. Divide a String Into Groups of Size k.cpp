class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();

        int i = 0;
        while (i < n) {
            string temp;
            for (int j = i; j < n && j<i+k; j++) temp.push_back(s[j]);
            i+=k;
            if (i < n) ans.push_back(temp);
            else {
                int len = k - temp.size();
                while (len--) {
                    temp.push_back(fill);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
