class Solution {
public:
    int result;

    void solve(int ind, vector<int>& nums, unordered_map<int, int>& mpp, int k){
        if(ind >= nums.size()){
           result++;
           return;
        }
        solve(ind+1, nums, mpp, k); // not-take

        if(!mpp[nums[ind] - k] && !mpp[nums[ind] + k]){ // Take
           mpp[nums[ind]]++;
           solve(ind+1, nums, mpp, k);
           mpp[nums[ind]]--;
        }

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        result = 0;
        unordered_map<int, int> mpp;

        solve(0, nums, mpp, k);
        return result-1;
    }
    
};
