//
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> fns;
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second==1){
                fns.push_back(it.first);
            }
        }
        return fns;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            maxi=max(nums[i], maxi);
        }
        int ans[maxi]={0};
        for(int i=0; i<n; i++){
            ans[nums[i]]++;
        }
        for(auto it: ans){
            if(ans[nums[it]]==1){
                fns.push_back(nums[it]);
            }
        }
        return fns;
    }
};
