class Solution {
private:
    bool isPossible(int dist,vector<int> &position,int m){
        int numBalls = 1;
        int last = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last >= dist){
                numBalls++;
                last = position[i];
                if(numBalls >= m){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());

        int s = 1;
        int e = position.back()-position[0];
        int ans = 1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(mid,position,m)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};