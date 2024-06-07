class Solution {
public:
    bool allZero(vector<int> &counter){
        for(auto &i : counter){
            if(i != 0){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // similiar to find anagram of s2 in s1
        int sizeOfWindow = s1.length();

        vector<int> counter(26,0);
        for(auto &it : s1){
            counter[it-'a']++;
        }

        int i=0,j=0;
        while(j<s2.length()){
            counter[s2[j]-'a']--;

            if(j-i+1 == sizeOfWindow){
                if(allZero(counter)){
                    return true;
                }
                counter[s2[i]-'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};