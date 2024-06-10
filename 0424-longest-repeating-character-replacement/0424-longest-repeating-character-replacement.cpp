class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i=0, j=0;
        int maxLength = 0, maxfreq = 0;
        unordered_map<char,int> mpp;

        while(j<n){
            mpp[s[j]]++;
            maxfreq = max(maxfreq,mpp[s[j]]);
            //element to convert = sizeOfArray - noOfDistinctElements
            while((j-i+1) - maxfreq > k){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};