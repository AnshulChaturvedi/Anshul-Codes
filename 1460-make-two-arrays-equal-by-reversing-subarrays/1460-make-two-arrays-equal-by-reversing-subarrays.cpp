class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto &it : target){
            mpp[it]++;
        }
        for(auto &it : arr){
            if(mpp.find(it) == mpp.end()) return false;
            mpp[it]--;
            if(mpp[it] == 0) mpp.erase(it);
        }
        return (mpp.size() == 0) ? true : false;
    }
};