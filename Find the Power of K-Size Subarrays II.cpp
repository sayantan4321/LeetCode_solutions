// Approach - Sliding Window
// T.C. -> O(N)
// S.C. -> O(1)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums; 
        int n = nums.size(), cnt =1; //initialize to 1
        vector<int> res(n-k+1, -1);

        for(int i=1; i<k; i++){ //For first Window
            if(nums[i] == nums[i-1]+1){
                cnt++;
            } else {
                cnt=1;
            }
        }
        if(cnt==k){
            res[0] = nums[k-1];
        }
        int i=1, j=k; //second window indexes
        while(j<n){
            if(nums[j] == nums[j-1]+1){
                cnt += 1;
            } else{
                cnt = 1;
            }
            if(cnt >= k){
                res[i] = nums[j];
            }
            i++;
            j++;
        }
        return res;
    }
};
