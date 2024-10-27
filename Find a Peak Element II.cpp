class Solution {
public:
    int maxRowIndex(vector<vector<int>>& matrix, int n, int m, int col){
        int maxValue = -1;
        int Index = -1;
        for(int i=0; i<n; i++){
            if(matrix[i][col] > maxValue){
                maxValue = matrix[i][col];
                Index = i;
            }
        }
        return Index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        int low = 0, high = m-1;
        while(low<= high){
            int mid = (low+high)/2;
            int rowIndex = maxRowIndex(matrix, n, m, mid);
            
            int left = mid-1 >= 0 ? matrix[rowIndex][mid-1] : -1;
            int right = mid+1 < m ? matrix[rowIndex][mid+1] : -1;

            if(matrix[rowIndex][mid] > left && matrix[rowIndex][mid] > right){
                return {rowIndex, mid};
            }
            else if(matrix[rowIndex][mid] < left) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};