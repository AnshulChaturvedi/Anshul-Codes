class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26);
        for(int i=0; i<s.size(); i++){
            lastIdx[s[i]-'a'] = i;
        }
        int st = 0, e = 0;
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            e = max(e, lastIdx[s[i]-'a']);
            if(i == e){
                ans.push_back(e-st+1);
                st = i + 1;
            }
        }
        return ans;
    }
};