// Approach: 1
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        ios::sync_with_stdio(false);
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n,0));

        if(lower+upper!=accumulate(colsum.begin(),colsum.end(),0)) return {};
        for(int j=0; j<n; j++){
           const int x = colsum[j];
           switch(x){
             case 0: 
                res[0][j]=res[1][j]=0;
                break;
             case 1 :
                if(upper>lower){
                    res[0][j]=1;
                    res[1][j]=0;
                    --upper;
                } 
                else{
                    res[0][j]=0;
                    res[1][j]=1;
                    --lower;
                }
                break;
             case 2:
                res[0][j]=res[1][j]=1;
                upper--;
                lower--;     
           }
           if(lower<0 || upper<0){
            return {};
           }
        }
        return res;
    }
};
