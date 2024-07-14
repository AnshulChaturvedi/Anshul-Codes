class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<n){
            if(formula[i] == '('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i] == ')'){
                unordered_map<string,int> curr = st.top();
                st.pop();
                i++;

                string mult;
                while(i<n && isdigit(formula[i])){
                    mult.push_back(formula[i]);
                    i++;
                }

                if(!mult.empty()){
                    int multInt = stoi(mult);
                    for(auto &it : curr){
                        string element = it.first;
                        int cnt = it.second;
                        curr[element] = cnt * multInt;
                    }
                }

                for(auto &it : curr){
                    string element = it.first;
                    int cnt = it.second;
                    st.top()[element] += cnt;
                }
            }
            else{
                string currEle;
                currEle.push_back(formula[i]);
                i++;

                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currEle.push_back(formula[i]);
                    i++;
                }
                
                string currCnt;
                while(i<n && isdigit(formula[i])){
                    currCnt.push_back(formula[i]);
                    i++;
                }

                int currCntInt = (currCnt.empty()) ? 1 : stoi(currCnt);
                st.top()[currEle] += currCntInt;
            }
        }
        map<string,int> sortedMap(st.top().begin(),st.top().end());
        string res;
        for(auto &it : sortedMap){
            string element = it.first;
            res += element;
            int cnt = it.second;
            if(cnt > 1)
                res += to_string(cnt);
        }
        return res;
    }
};