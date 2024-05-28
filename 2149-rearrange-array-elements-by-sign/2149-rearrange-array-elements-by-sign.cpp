class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos,neg;
        for(auto num : nums){
            if(num>0){
                pos.push_back(num);
            }
            else{
                neg.push_back(num);
            }
        }
        vector<int> result;
        for(int i=0;i<pos.size();i++){
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }
        return result;
    }
};