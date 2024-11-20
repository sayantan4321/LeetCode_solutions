class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, CurrWindowSum =0;
        int i=0, j=0;

        unordered_set<int> st;
        while(j < n){
            // Adjust the window if nums[j] is already in the set
            while(st.count(nums[j])){
               CurrWindowSum -= nums[i]; 
               st.erase(nums[i]);
               i++;
            }
            CurrWindowSum += nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k){ //when window size has reached
               sum = max(sum, CurrWindowSum);
               CurrWindowSum -= nums[i];
               st.erase(nums[i]);
               i++;
            }
            j++;
        }
        return sum;
    }
};
