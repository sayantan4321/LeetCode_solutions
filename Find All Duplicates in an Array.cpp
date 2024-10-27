----------- Approach - 1 -----------
// Using Map
  T.C. ->  O(N) 
  S.C. -> O(N)

-------- Approach - 3 --------
  T.C. -> O(N) 
  S.C. -> O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        set<int> stt;
        for(int i=0; i<nums.size(); i++){
            if(stt.count(nums[i])){
                ans.push_back(nums[i]);
            }
            else{
                stt.insert(nums[i]);
            }
        }
        return ans;
    }
};
