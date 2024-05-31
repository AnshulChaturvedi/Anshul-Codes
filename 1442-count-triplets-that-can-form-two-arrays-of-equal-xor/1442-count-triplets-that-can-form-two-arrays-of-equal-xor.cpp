class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(),arr.end());
        prefixXOR.insert(prefixXOR.begin(),0);
        int n = prefixXOR.size();
        for(int i=1;i<n;i++){
            prefixXOR[i] ^= prefixXOR[i-1];
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(prefixXOR[k] == prefixXOR[i]){
                    cnt += k-i-1;
                }
            }
        }
        return cnt;
    }
};