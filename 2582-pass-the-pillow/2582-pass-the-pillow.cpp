class Solution {
public:
    int passThePillow(int n, int time) {
        if(time < n) return time+1;
        int noOfRounds = time/(n-1);
        int remSteps = time%(n-1);
        if(noOfRounds&1){
            return n-remSteps;
        }
        else{
            return remSteps+1;
        }
    }
};