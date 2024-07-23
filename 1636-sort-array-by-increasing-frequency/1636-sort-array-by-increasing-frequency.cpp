class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        // {element, freq}
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> res;
        // {freq, element}
        for(auto &it:mpp){
            res.push_back({it.second,it.first});
        }
        sort(res.begin(),res.end(),Solution::cmp);
        vector<int> ans;
        for(auto &it : res){
            for(int i=0;i<it.first;i++)
                ans.push_back(it.second);
        }
        return ans;
    }
};