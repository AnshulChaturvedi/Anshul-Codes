using ll = long long;

void merge(vector<int>& nums,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        nums[i] = temp[i-low];
    }
}

ll countPairs(vector<int> &nums,int low,int mid,int high){
    ll cnt = 0;
    int right = mid+1;
    for(int i=low;i<=mid;i++){
        while(right <= high && (ll)nums[i] > (ll)2 * nums[right]){
            right++;
        }
        cnt += (ll)right - (mid+1);
    }
    return cnt;
}

ll mergeSort(vector<int>& nums,int low,int high){
    ll cnt = 0;
    if(low>=high){
        return 0;
    }
    ll mid = (low+high)/2;
    cnt += mergeSort(nums,low,mid);
    cnt += mergeSort(nums,mid+1,high);
    cnt += countPairs(nums,low,mid,high);
    merge(nums,low,mid,high);
    return cnt;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ll cnt = 0;
        cnt += mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};