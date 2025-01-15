class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> arr(n);
        unordered_map<int, int> mpp;
        
        for(int i=0; i<n; i++){
            int temp1 = A[i], temp2 = B[i];
            int cnt =0;
            mpp[temp1]++, mpp[temp2]++;
            for(auto& m:mpp){
                if(m.second == 2){
                    cnt++;
                }
            }
            // if(mpp[temp1].second ==2) cnt++;
            // if(mpp[temp2].second ==2) cnt++;

            arr[i] =cnt;
        }
        return arr;
    }
};
