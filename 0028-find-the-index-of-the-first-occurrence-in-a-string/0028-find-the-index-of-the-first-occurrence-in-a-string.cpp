class Solution {
public:
    int strStr(string a, string b) {
        // return first occ of b in a
        int n = a.size(), m = b.size();
        if(n < m) return -1;
        
        int i=0, j=0;
        int ans = -1;
        while(i<n && j<m){
            if(a[i] == b[j]){
                ans = i;
                while(i<n && j<m && a[i] == b[j]){
                    i++;
                    j++;
                }
                if(j==m) return ans;
                else{
                    j=0;
                    i = ans+1;
                    ans = -1;
                }
            }
            else{
                i++;
            }
        }
        return ans;
    }
};