class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<=0) return {};
        vector<vector<int>>  res(n, vector<int> (n));
        int num = 1;
        int top=0, bottom=n-1, left=0, right=n-1;

        while(top<=bottom && left<=right){
            //top row
            for(int i=left; i<=right; i++){
                res[top][i] = num++;
            }
            top++;
            // right column
            for(int i=top; i<=bottom; i++){
                res[i][right] = num++;
            }
            right--;
            // bottom row
            if(top<=bottom){
                for(int i=right;  i>=left; i--){
                    res[bottom][i]=num++;
                }
                bottom--;
            }
            //for left column 
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    res[i][left]=num++;
                }
                left++;
            }
        }
        return res;
    }
};
