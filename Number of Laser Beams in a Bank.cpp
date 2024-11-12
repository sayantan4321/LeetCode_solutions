//T.C : O(m*n) - Total number of characters in all string
//S.C : O(1)
//----------------------------C++---------------------//
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n= bank.size();
        int prevdevicecnt = 0, result=0;
        
        for(int i=0; i<n; i++){
            int currdevicecnt=0;
            for(char &ch: bank[i]){
                if(ch == '1') currdevicecnt++;
            }
            result += (prevdevicecnt*currdevicecnt);

            if(currdevicecnt != 0){
                prevdevicecnt = currdevicecnt;
            }
            
        }
        return result;
    }
};
