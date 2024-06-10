class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i=0, j = 0;
        int cnt = 0;
        unordered_map<char,int> mpp;
        while(j<n){
            mpp[s[j]]++;

            while(mpp.size() >= 3){
                cnt += n-j;
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};