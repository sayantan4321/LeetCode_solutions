// Approach - 1
// T.C. -.O(N^2)
//S.C. -> O(1)
class Solution {
public:
    int sumofDigits(int num){
        int sum = 0;
        while(num > 0){
           int d = num%10;
           sum = sum+d;
           num = num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int maxSum = -1;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(sumofDigits(nums[i]) == sumofDigits(nums[j])){
                    maxSum = max(maxSum, nums[i]+nums[j]);
                }
            }
        }
        return maxSum;
    }
};
