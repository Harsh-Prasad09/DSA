class Solution {
public:
    string sortString(int n) {
        string str = to_string(n);
        sort(begin(str), end(str));
        
        return str;
    }

    bool reorderedPowerOf2(int n) {
        string target = sortString(n);

        for (int i = 0; i<32; i++) {
            if (sortString(1<<i) == target) return true;
        }    

        return false;
    }
};
