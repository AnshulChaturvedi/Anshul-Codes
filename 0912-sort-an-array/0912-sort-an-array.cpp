class Solution {
private:
    void merge(int s,int mid,int e,vector<int> &nums){
        vector<int> temp;
        int l=s, r=mid+1;
        while(l<=mid && r<=e){
            if(nums[l] < nums[r]){
                temp.push_back(nums[l++]);
            }
            else{
                temp.push_back(nums[r++]);
            }
        }
        while(l<=mid){
            temp.push_back(nums[l++]);
        }
        while(r<=e){
            temp.push_back(nums[r++]);
        }
        for(int i=s;i<=e;i++){
            nums[i] = temp[i-s];
        }
    }

    void mergeSort(int s,int e,vector<int> &nums){
        if(s >= e) return;
        int mid = s + (e-s)/2;
        mergeSort(s,mid,nums);
        mergeSort(mid+1,e,nums);
        merge(s,mid,e,nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};