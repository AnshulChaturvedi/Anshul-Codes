class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(),sortedNums.end());
        unordered_map<int,deque<int>> mpp1;
        unordered_map<int,int> mpp2;
        int grp = 0;
        mpp1[grp].push_back(sortedNums[0]);
        for(int i=1; i<n; i++){
            if(sortedNums[i] - sortedNums[i-1] > limit){
                grp++;
            }
            mpp1[grp].push_back(sortedNums[i]);
            mpp2[sortedNums[i]] = grp;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            int respGrp = mpp2[nums[i]];
            ans.push_back(mpp1[respGrp].front());
            mpp1[respGrp].pop_front();
        }
        return ans;
    }
};