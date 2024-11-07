--------------Approach -1 ---------------
// simple using map to track count and sliding window.
T.C. -> O(N)
S.C. -> O(1)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxlen =0;
        unordered_map<int,int> mpp;
        int i=0, j=0;

        while(j < nums.size()){
            mpp[nums[j]]++;
            if(mpp[nums[j]] > k){
                // we have to remove nums[i] freq till it matches with nums[j]
                while(nums[i] != nums[j]){ 
                    mpp[nums[i]]--;
                    i++;
                }
                mpp[nums[i]]--; // when we found we reduce only one time
                i++;
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};
