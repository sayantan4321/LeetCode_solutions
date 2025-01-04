class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> cummSum(n);
        cummSum[0] = nums[0];

        for(int i=1; i<nums.size(); i++){
            cummSum[i] = cummSum[i-1] + nums[i];
        }
        int split = 0;
        for(int i=0; i<n-1; i++){
            long long leftSum = cummSum[i];
            long long rightSum = cummSum[n-1] - cummSum[i];

            if(leftSum >= rightSum) split++;
        }
        return split;
    }
};
