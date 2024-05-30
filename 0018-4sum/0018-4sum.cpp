class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<4) return ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<n;j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int x=j+1;
                int y=n-1;

                while(x<y){

                    long long sum = (long long)nums[i] + nums[j] + nums[x] + nums[y];

                    if(sum < target){
                        x++;
                    }
                    else if(sum > target){
                        y--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                        x++;
                        y--;

                        while(x<y && nums[x] == nums[x-1]) x++;
                        while(x<y && nums[y] == nums[y+1]) y--;
                    }
                }
            }
        }
        return ans;
    }
};