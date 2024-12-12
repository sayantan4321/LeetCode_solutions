class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,int>>interval(nums.size());
      
        for(int i=0;i<nums.size();i++){
          interval[i]={nums[i]-k,nums[i]+k};
        }  
        sort(interval.begin(),interval.end());
        int ans=INT_MIN,j=0;
        for(int i=0;i<nums.size();i++){
          while(interval[j].second<interval[i].first) 
             j++;
          ans=max(ans,i-j+1);
        }
        return ans; 
    }
};
