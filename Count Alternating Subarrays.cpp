-------Approach -> 1 -----------
// count total subarray's ending with j    
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int i=0, j=1;
        long long cnt =1;
        
        while(j < nums.size()){
           if(nums[j-1] == nums[j]){  
                i=j;
           }
           cnt += (j-i+1);
           j++;
        }
        return cnt;
    }
};

---------- Approach ->2 -----------
//Optimal : Count Subaraay's using the length.
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int j = i;

            while (j + 1 < n && nums[j] != nums[j + 1]) {
                ++j;
            }

            int len = j - i + 1;
            count += (long long)len * (len + 1) / 2;
            i = j;
        }

        return count;
    }
};
