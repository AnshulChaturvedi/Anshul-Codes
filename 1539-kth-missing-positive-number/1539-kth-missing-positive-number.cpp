class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st;
        for(auto it : arr){
            st.insert(it);
        }
        int x = 1;
        for(int i=1;i<=1000000;i++){
            if(st.find(i) == st.end()){
                if(x == k) return i;
                x++;
            }
        }
        return 0;
    }
};