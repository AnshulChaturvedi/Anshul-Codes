class Solution {
public:
    int memo[1001][1001];
    int solve(int s,int e,string &str){
        // while(s<=e){
        //     if(str[s] == str[e]){
        //         s++;
        //         e--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;
        if(s>=e){
            return 1;
        }
        if(memo[s][e] != -1){
            return memo[s][e];
        }
        if(str[s] == str[e]){
            return memo[s][e] = solve(s+1,e-1,str);
        }
        return memo[s][e] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        memset(memo,-1,sizeof(memo));
        int maxLength = INT_MIN;
        int st = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
                    if(j-i+1 > maxLength){
                        maxLength = j-i+1;
                        st = i;
                    }
                        
                }
            }
        }
        return s.substr(st,maxLength);
    }
};