class Solution {
private:
    bool isPossible(unordered_map<char,int> &mpp1,unordered_map<char,int> &mpp2){
        for(auto &it : mpp1){
            if(mpp2[it.first] < it.second){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m < n) return "";

        unordered_map<char,int> mpp1,mpp2;
        for(auto &ch : t){
            mpp1[ch]++;
        }

        int i=0, j=0;
        int minLength = INT_MAX;
        int start = 0;

        while(j<m){
            mpp2[s[j]]++;
            while(isPossible(mpp1,mpp2)){
                if(j-i+1 < minLength){
                    minLength = j-i+1;
                    start = i;
                }
                mpp2[s[i]]--;
                if(mpp2[s[i]] == 0){
                    mpp2.erase(mpp2[s[i]]);
                }
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? "" : s.substr(start,minLength);
    }
};