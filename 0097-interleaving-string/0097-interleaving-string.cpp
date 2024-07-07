class Solution {
public:
    int memo[101][101];
    bool solve(int i,int j,string &s1,string &s2,string &s3,int &n1,int &n2,int &n3){
        if(i+j>=n3) return true;
        if(memo[i][j] != -1) return memo[i][j];
        if(i<n1 && j<n2 && s1[i] == s3[i+j] && s2[j] == s3[i+j]){
            return memo[i][j] = solve(i+1,j,s1,s2,s3,n1,n2,n3) || solve(i,j+1,s1,s2,s3,n1,n2,n3);
        }
        else if(i<n1 && s1[i] == s3[i+j]){
            return memo[i][j] = solve(i+1,j,s1,s2,s3,n1,n2,n3);
        }
        else if(j<n2 && s2[j] == s3[i+j]){
            return memo[i][j] = solve(i,j+1,s1,s2,s3,n1,n2,n3);
        }
        return memo[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2=s2.length(), n3=s3.length();
        memset(memo,-1,sizeof(memo));
        if(n1 + n2 != n3) return false;
        return solve(0,0,s1,s2,s3,n1,n2,n3);
    }
};