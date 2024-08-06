class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        for(auto &c : word){
            mpp[c]++;
        }
        vector<int> v;
        for(auto &it : mpp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end(),greater<>());
        int sum = 0;
        int pushes = 1;
        for(int i=0;i<v.size();i++){
            sum += (pushes*v[i]);
            if((i+1)%8 == 0){
                pushes++;
            }
        }
        return sum;
    }
};