class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        int cnt = 0;
        map<int,int> mpp1;
            //Ball, Color
        map<int,int> mpp2;
            //color, balls
        for(int i=0; i<queries.size(); i++){
            int ball = queries[i][0];
            int col = queries[i][1];
            if(mpp1.count(ball)){
                int prev_col = mpp1[ball];
                mpp2[prev_col]--;
                if(mpp2[prev_col] == 0){
                    cnt--;
                }
            }
            mpp2[col] += 1;
            if(mpp2[col] == 1){
                cnt++;
            }
            mpp1[ball] = col;
            res.push_back(cnt);
        }
        return res;
    }
};