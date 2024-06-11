class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //Custom Sort function Approach
        unordered_map<int,int> mpp;
        for(int i=0;i<arr2.size();i++){
            mpp[arr2[i]] = i;
        }
        for(auto &it : arr1){
            if(mpp.find(it) == mpp.end()){
                mpp[it] = INT_MAX;
            }
        }

        auto lambda = [&](int &num1,int &num2){
            if(mpp[num1] == mpp[num2]){
                return num1 < num2;
            }
            return mpp[num1] < mpp[num2];
        };

        sort(arr1.begin(),arr1.end(),lambda);

        return arr1;

    }
};