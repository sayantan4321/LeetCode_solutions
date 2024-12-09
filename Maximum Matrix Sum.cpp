class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cntNegetive = 0, smallestVal = INT_MAX;
        long long sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] < 0) cntNegetive++;
                smallestVal = min(smallestVal, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        } 
        // **We have to remove the exess min value from total and also have to do the reduction of that smallestVal
        if(cntNegetive % 2 != 0) return sum - 2*smallestVal; // that's Why multiplied by 2.
        return sum;
    }
};
