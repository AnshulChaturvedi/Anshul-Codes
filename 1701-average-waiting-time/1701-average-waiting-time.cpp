class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double st = 0, finish = 0;
        double total = 0;
        for(int i=0;i<n;i++){
            if(customers[i][0] > finish){
                finish = customers[i][0] + customers[i][1];
                total += finish - customers[i][0];
            }
            else{
                finish += customers[i][1];
                total += finish - customers[i][0];
            }
        }
        return total/n;
    }
};