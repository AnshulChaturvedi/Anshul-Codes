class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto transform = [&](int num){
            string s = to_string(num);
            string transformed;
            for(char c : s){
                transformed += to_string(mapping[c-'0']);
            }
            return stoi(transformed);
        };

        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({transform(nums[i]),i});
        }
        sort(vec.begin(),vec.end());

        vector<int> ans;
        for(auto &it : vec){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};