class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxRight(n);
        maxRight[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], nums[i]);
        }

        int ramp = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            while(i < j && nums[i] > maxRight[j]) {
                i++;
            }

            ramp = max(ramp, j-i);
            j++;
        }

        return ramp;
        // int j = nums.size() - 1;
        // int maxlen = 0;
        // while(j>0){
        //     for(int i=0; i<j; i++){
        //         if(nums[i] <= nums[j]){
        //             maxlen = max(maxlen, j-i);
        //         }
        //     }
        //     j--;
        // }
        // return maxlen;
    }
};
