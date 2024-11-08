---------------- Approach -> 1 -----------------------
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt_one = count(s.begin(), s.end(), '1');
        int n = s.size();
        string res = string(n,'0');

        int j=0;
        while(cnt_one > 1){
            res[j] = '1';
            j++;
            cnt_one --;
        }
        res[n-1] = '1'; 
        return res;
    }
};


-------------------- Approach -> 2 ------------------
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        string res = string(n,'0');

        int i=0;
        for(char &ch : s){
            if(ch == '1'){
                if(res[n-1] == '1'){
                    res[i] = '1';
                    i++;
                }
                else res[n-1] = '1';
            }
        }
        return res;
    }
};    
