class Solution {
private:
    void solve(int i,string path,long resSoFar,long prevNum,vector<string> &ans,const string &num,int target){
        if(i == num.size()){
            if(resSoFar == target){
                ans.push_back(path);
            }
            return;
        }
        for(int j=i;j<num.size();j++){
            if(j>i && num[i] == '0') break;

            string currStr = num.substr(i,j-i+1);
            long currNum = stol(currStr);

            if(i == 0){
                solve(j+1,path + currStr,currNum,currNum,ans,num,target);
            }
            else{
                solve(j+1,path + "+" + currStr,resSoFar + currNum, currNum,ans,num,target);
                solve(j+1,path + "-" + currStr,resSoFar - currNum, -currNum,ans,num,target);
                solve(j+1,path + "*" + currStr,resSoFar - prevNum + prevNum * currNum, prevNum * currNum,ans, num, target);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0,"",0,0,ans,num,target);
        return ans;
    }
};