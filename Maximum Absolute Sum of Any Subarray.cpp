class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int sum = nums[i];
            for(int j=i+1; j<n; j++){
                sum += nums[j];
                maxSum = max(abs(sum), maxSum);
            }
        }
        int minSum = 0;
        for(int i=0; i<n; i++){
            int sum = nums[i];
            for(int j=i+1; j<n; j++){
                sum += nums[j];
                minSum = min(abs(sum), minSum);
            }
        }
        return max(abs(maxSum), abs(minSum));
    }
};
