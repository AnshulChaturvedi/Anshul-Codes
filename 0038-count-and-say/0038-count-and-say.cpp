class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string temp = "1";
        for(int i=2; i<=n; i++){
            string curr = "";
            int cnt = 1;
            for(int j=1; j<=temp.size(); j++){
                if(j<temp.size() && temp[j] == temp[j-1]){
                    cnt++;
                }
                else{
                    curr += to_string(cnt);
                    curr += temp[j-1];
                    cnt = 1;
                }
            }
            temp = curr;
        }
        return temp;
    }
};