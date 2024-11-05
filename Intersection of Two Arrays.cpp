class Solution {
public:
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(auto it: nums1){
            mpp[it]++;
        }
        for(int i=0; i<nums2.size(); i++){
            if(mpp.find(nums2[i]) != mpp.end()){
                ans.push_back(nums2[i]);
                mpp.erase(nums2[i]);
            }
        }
        return ans;
    }
};
