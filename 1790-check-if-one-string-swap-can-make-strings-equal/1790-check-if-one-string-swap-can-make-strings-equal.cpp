class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int firstDiffIdx = 0, secondDiffIdx = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                cnt++;
                if(cnt > 2) return false;
                else if(cnt == 1) firstDiffIdx = i;
                else secondDiffIdx = i;
            }
        }
        return s1[firstDiffIdx] == s2[secondDiffIdx] && 
                s1[secondDiffIdx] == s2[firstDiffIdx];
    }
};