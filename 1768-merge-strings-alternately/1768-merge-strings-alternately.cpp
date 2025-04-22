class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i=0, n1 = word1.size(), n2 = word2.size();
        while(i < n1 && i < n2){
            s.push_back(word1[i]);
            s.push_back(word2[i]);
            i++;
        }
        if(i < n1) s.append(word1.data() + i, n1 - i);
        if(i < n2) s.append(word2.data() + i, n2 - i);
        return s;
    }
};