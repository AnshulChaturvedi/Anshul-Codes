class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto num : nums) pq.push(num);
    }
    
    int add(int val) {
        // pq.push(val);
        // vector<int> keep;
        // while(K--){
        //     keep.push_back(pq.top());
        //     pq.pop();
        // }
        // int ans = pq.top();
        // int size = keep.size();
        // while(size--){
        //     pq.push(keep[size]);
        // }
        // return ans;
        pq.push(val);
        while(pq.size()>K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */