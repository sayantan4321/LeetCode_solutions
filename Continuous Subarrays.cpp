class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mpp;
        int i=0, j=0;
        long long count =0;

        while(j < n){
            mpp[nums[j]]++;
            while(abs(mpp.rbegin()->first - mpp.begin()->first) > 2){
                mpp[nums[i]] -= 1; // shrink the window
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};
