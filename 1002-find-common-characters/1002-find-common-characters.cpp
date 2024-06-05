class Solution {
public:
    void fillCount(string word,vector<int>& lower){
        for(auto &it : word){
            lower[it-'a']++;
        }
    }

    
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> lower(26,0);
        
        fillCount(words[0],lower);

        for(int i=1;i<n;i++){
            vector<int> temp(26);
            fillCount(words[i],temp);

            for(int j=0;j<26;j++){
                lower[j] = min(lower[j],temp[j]);
            }
            
        }

        vector<string> ans;
        for(int i=0;i<26;i++){
            if(lower[i] != 0){
                while(lower[i]--){
                    ans.push_back(string(1,i+'a'));
                }
            }
        }

        return ans;
    }
};