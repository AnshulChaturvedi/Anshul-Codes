class Solution {
public:
    int memo[101][101][201];
    bool solve(int i,int j,int k,string &s1,string &s2,string &s3,int &n1,int &n2,int &n3){
        if(k>=n3) return true;
        if(memo[i][j][k] != -1) return memo[i][j][k];
        if(i<n1 && j<n2 && s1[i] == s3[k] && s2[j] == s3[k]){
            return memo[i][j][k] = solve(i+1,j,k+1,s1,s2,s3,n1,n2,n3) || solve(i,j+1,k+1,s1,s2,s3,n1,n2,n3);
        }
        else if(i<n1 && s1[i] == s3[k]){
            return memo[i][j][k] = solve(i+1,j,k+1,s1,s2,s3,n1,n2,n3);
        }
        else if(j<n2 && s2[j] == s3[k]){
            return memo[i][j][k] = solve(i,j+1,k+1,s1,s2,s3,n1,n2,n3);
        }
        return memo[i][j][k] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2=s2.length(), n3=s3.length();
        memset(memo,-1,sizeof(memo));
        if(n1 + n2 != n3) return false;
        return solve(0,0,0,s1,s2,s3,n1,n2,n3);
    }
};