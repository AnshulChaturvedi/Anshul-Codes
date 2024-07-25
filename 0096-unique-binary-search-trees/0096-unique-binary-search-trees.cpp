class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        vector<int> catalan(n+1,0);
        catalan[0] = catalan[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                catalan[i] += catalan[j]*catalan[i-j-1];
            }
        }
        return catalan[n];
    }
};