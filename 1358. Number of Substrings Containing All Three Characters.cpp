class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> arr(3, -1);
        for (int i = 0; i<n; i++){
            arr[s[i] - 'a'] = i;

            ans += *min_element(begin(arr), end(arr)) + 1;
        }
        return ans;
    }
};
