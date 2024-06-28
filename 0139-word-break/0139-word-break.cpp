class Solution {
public:
    bool isPresent(int i,int j,string s,unordered_set<string>& st){
        return st.find(s.substr(i,j-i+1)) != st.end();
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();
        
        vector<int> dp(n+1,false);
        //dp[i] represents wheather there exists a substr from 0 to i present in dict
        dp[0] = true; //no word string can be made from dict
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && isPresent(j,i-1,s,st)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};