class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        for(int i=0;i<n;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if(!ans.empty() && e<=ans.back()[1]){
                continue;
            }
            
            for(int j=i+1;j<n;j++){
                if(intervals[j][0] <= e){
                    e = max(e,intervals[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({s,e});
        }
        return ans;
    }
};