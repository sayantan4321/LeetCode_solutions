----------- Aprroach - 1 --------------
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        for(int i=0; i<nums.size(); i++){
            int opposite = -(nums[i]);
            for(int j=0; j<nums.size(); j++){
                if(nums[j] == opposite){
                    result = max(result, nums[i]);
                }
            }
        }
        return result;
    }
};

------------ Approach - 2 ------------
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // int res = -1;
        // unordered_map<int, int> mpp;



        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        while(i < j){
           if(-nums[i] == nums[j]) return nums[j];

           if(-nums[i] < nums[j]){
              j--;
           }
           else i++;
        }
        return -1;

        // int result = -1;
        // for(int i=0; i<nums.size(); i++){
        //     int opposite = -(nums[i]);
        //     for(int j=0; j<nums.size(); j++){
        //         if(nums[j] == opposite){
        //             result = max(result, nums[i]);
        //         }
        //     }
        // }
        // return result;
    }
};
