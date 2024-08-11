class Solution {
public:
    int sign(int val){
        if(val>0) return 1;
        return -1;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto &it : asteroids){
            bool destroyed = false;
            while(!res.empty() && sign(res.back())>0 && sign(it)<0){// checking only when the they are actually colliding or not test case(129)
                if(abs(res.back()) == abs(it)){
                    res.pop_back();
                    destroyed = true;
                    break;
                }
                else if(abs(res.back()) < abs(it)){
                    res.pop_back();
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) res.push_back(it);
        }
        return res;
    }
};