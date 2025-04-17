class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        for(int i = 0;i < (1 << n);++i) {
            string temp;
            bool flag = true;
            for(int j = 0;j < n;++j) {
                temp += ((i & (1 << j)) ? '1' : '0');
                if (j > 0 and temp[j-1] == '0' and temp[j] == '0') { flag = false; break; }
            }
            if (flag) ans.push_back(temp);
        }
        return ans;
    }
};
