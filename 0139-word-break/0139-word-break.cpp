class Solution {
private:
    bool solve(int idx,string s,unordered_set<string> &st,vector<int> &memo){
        if(idx == s.size()){
            return true;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        for(int i=idx;i<s.size();i++){
            string val = s.substr(idx,i-idx+1);
            if(st.find(val) != st.end()){
                if(solve(i+1,s,st,memo) == true){
                    return memo[idx] = true;
                }
            }
        }
        return memo[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> memo(s.size(),-1);
        return solve(0,s,st,memo);
    }
};