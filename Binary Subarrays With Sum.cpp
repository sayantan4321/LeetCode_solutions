// Brute  Force-----> Approach 1
class Solution {
public:
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == goal){
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};

---------- Approach - 2 --------------------
// Prefix Sum    
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int, int>mpp;
        mpp[0]=1;
        int presum=0;
        for(int i=0; i<nums.size(); i++){
           presum+= nums[i];
           int remove= presum - k;
           cnt+= mpp[remove];
           mpp[presum]+= 1;
        } 
       return cnt;
    }
};
----------- Approach -3 ----------
// Sliding Window
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int  n = nums.size();
        int i=0, j=0;
        int windowSum = 0, result = 0;

        while(j < n){
                windowSum += nums[j];
                int cntZero = 0;
                while(i<n && (nums[i]==0 || windowSum > goal)) {
                        if(nums[i]==0) cntZero++;
                        else cntZero =0;
                        
                        windowSum -= nums[i];
                        i++;
                }
                if(windowSum == goal) result += 1 + cntZero;
        }
        return result;    
    }
};
