class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int, int> mpp;

       mpp[0]= -1;
       int maxlen=0;
       int currsum = 0;

       for(int i=0; i<n; i++)  {
          if(nums[i]==1) currsum += 1;
          else currsum = currsum -1;

          if(mpp.find(currsum) != mpp.end()){
            maxlen = max(maxlen, i-mpp[currsum]);
          }
          else{
            mpp[currsum] = i;
          }
       }
       return maxlen;
    }
};