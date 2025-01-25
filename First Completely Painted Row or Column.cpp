// Approach - 1 
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       unordered_map<int, int> mpp;
       int ans = INT_MAX;
       for(int i=0; i<arr.size(); i++){
          mpp[arr[i]] = i;
       } 
       for(int i=0; i<mat.size(); i++){
          int temp = INT_MIN;
          for(int j=0; j<mat[0].size(); j++){
              if(mpp.find(mat[i][j]) != mpp.end()){
                 temp = max(temp, mpp[mat[i][j]]);
              }
          }
          ans = min(ans, temp);
       }
       for(int i=0; i<mat[0].size(); i++){
          int temp = INT_MIN;
          for(int j=0; j<mat.size(); j++){
              if(mpp.find(mat[j][i]) != mpp.end()){
                 temp = max(temp, mpp[mat[j][i]]);
              }
          }
          ans = min(ans, temp);
       }
       return ans;
    }
};
