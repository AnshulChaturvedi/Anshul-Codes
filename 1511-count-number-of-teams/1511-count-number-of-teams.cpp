class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int j=1;j<rating.size()-1;j++){
            int cntLeftL=0, cntLeftS=0;
            for(int i=0;i<j;i++)
                if(rating[i]<rating[j]) cntLeftS++;
                else cntLeftL++;
            int cntRightL=0, cntRightS=0;
            for(int k=j+1;k<rating.size();k++)
                if(rating[k]<rating[j]) cntRightS++;
                else cntRightL++;
            ans += cntLeftL*cntRightS + cntLeftS*cntRightL;
        }
        return ans;
    }
};