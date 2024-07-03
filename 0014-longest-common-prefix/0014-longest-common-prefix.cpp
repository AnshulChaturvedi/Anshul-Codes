class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";

        string res = "";
        string s1 = strs[0];
        for(int i=0;i<s1.size();i++){
            for(int j=1;j<n;j++){
                if(i >= strs[j].size() || s1[i] != strs[j][i]){
                    return res;
                }
            }
            res += s1[i];
        }
        return res;
    }
};