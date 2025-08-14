class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.length();
        int i = 0, j = 2;
        while (j < n) {
            if (num[i] == num[i+1] && num[i] == num[j]) {
                if (ans.empty() || ans[0] < num[i]) ans = num.substr(i, 3);
            }

            i++;
            j++;
        }

        return ans;
    }
};
