class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        unordered_map<char,int> mpp;
        for(int i=0;i<word.size();i++){
            if(word[i] >= 'a' && word[i] <= 'z')
                mpp[word[i]] = i;
        }
        for(int i=word.size()-1;i>=0;i--){
            if(word[i] >= 'A' && word[i] <= 'Z')
                mpp[word[i]] = i;
        }
        for(auto it : mpp){
            if(it.first >= 'a' && it.first <= 'z'){
                char c = toupper(it.first);
                if(mpp.find(c) != mpp.end() && it.second < mpp[c]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};