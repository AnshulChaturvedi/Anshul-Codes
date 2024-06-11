class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;

        map<int,int> mpp;
        for(auto & it : arr1){
            mpp[it]++;
        }

        for(auto &num : arr2){
            if(mpp.find(num) != mpp.end()){
                while(mpp[num]--){
                    ans.push_back(num);
                }
                mpp.erase(num);
            }
        }
        for(auto &it : mpp){
            while(it.second--){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};