class Solution {
// private:
//     int convertToDecimal(string s){
//         int ans=0;
//         long long p2 = 1;
//         for(int i=s.length()-1;i>=0;i--){
//             if(s[i] == '1'){
//                 ans += p2;
//             }
//             p2 = p2 * 2;
//         }
//         return ans;
//     }
public:
    int numSteps(string s) {        
        // int num = convertToDecimal(s);
        // int cnt = 0;
        // while(num != 1){
        //     if(num&1){
        //         num += 1;
        //     }
        //     else{
        //         num /= 2;
        //     }
        //     cnt++;
        // }
        // return cnt;

        int cnt = 0;
        while(s != "1"){
            if(s.back() == '1'){//if s[i] == 1 this means an od  number it means add 1 in the end
                int i = s.length()-1;
                while(i>=0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                if(i>=0){
                    s[i] = '1';
                }else{
                    s.insert(s.begin(),'1');
                }
            }
            else{//if (s[i] == 0) means an even no. then divide it by 2;
                s.pop_back();
            }
            cnt++;
        }
        return cnt;
    }
};