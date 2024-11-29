class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        bool found = false;

        // for(int i=0; i<n; i++){
        //     int sum =0;
        //     for(int j=i; j<n; j++){
        //         sum += nums[j];
        //         if(j-i+1 >= l && j-i+1 <= r && sum > 0){
        //             minSum = min(minSum, sum);
        //             found = true;
        //         }
        //     }
        // }
        // return found? minSum:-1;
        
        for(int k=l; k<=r; ++k){
            int sum =0;
            for(int i=0; i<n; ++i){ // for each kgth of l to r window will move
                sum += nums[i];
                if(i >= k-1){ // increase 1 element at a time
                   if(sum > 0){
                     minSum = min(minSum, sum);
                     found = true;
                   }
                   sum -= nums[i-k+1]; // remove leftmost ele after calculate minsum
                }
                 
            }
        }
        return found ? minSum : -1; 
    }
};
