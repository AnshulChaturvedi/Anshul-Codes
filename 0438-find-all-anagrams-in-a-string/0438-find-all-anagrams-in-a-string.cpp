class Solution {
private:
    bool allZero(vector<int> &counter){
        for(auto &it : counter){
            if(it != 0){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> counter(26,0);
        for(auto &it : p){
            counter[it-'a']++;
        }
        vector<int> ans;
        int i=0, j=0;
        while(j<s.length()){
            counter[s[j]-'a']--;

            while(j-i+1 == p.length()){
                if(allZero(counter)){
                    ans.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};