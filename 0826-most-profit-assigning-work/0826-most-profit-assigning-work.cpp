class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        priority_queue<pair<int,int>> pq; //maxHeap

        for(int i=0;i<profit.size();i++){
            pq.push({profit[i],difficulty[i]});
        }
        sort(worker.begin(),worker.end(),greater<int> ());

        int maxProfit = 0;
        int i=0;
        while(i<worker.size() && !pq.empty()){
            if(pq.top().second > worker[i]){
                pq.pop();
            }
            else{
                maxProfit += pq.top().first;
                i++;
            }
        }
        return maxProfit;
    }
};