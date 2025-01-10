class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxfreq(26,0);
        for(int i=0; i<words2.size(); i++){
            vector<int> freq(26,0);
            for(auto c : words2[i]){
                freq[c-'a']++;
            }
            for(int j=0; j<26; j++){
                maxfreq[j] = max(maxfreq[j],freq[j]);
            }
        }

        vector<string> ans;

        for(int i=0; i<words1.size(); i++){
            vector<int> freq(26,0);
            for(auto c : words1[i]){
                freq[c-'a']++;
            }
            bool valid = true;
            for(int j=0; j<26; j++){
                if(freq[j] < maxfreq[j]){
                    valid = false;
                    break;
                }
            }
            if(valid) ans.push_back(words1[i]);
        }
        return ans;
    }
};