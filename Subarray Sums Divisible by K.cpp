class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
               sum+= nums[j];
               if(sum%k==0) cnt++;
            }
        }
        return cnt;
    }
};

//OPTIMAL
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size(), cnt=0;
        int presum=0;
        unordered_map<int, int> mpp;
        mpp[0]=1;
        for(int i=0; i<n; i++){
            presum+= nums[i];
            int rem= presum%k;
            if(rem<0){
                rem+=k;
            }
            if(mpp.find(rem)!=mpp.end()){
                cnt+= mpp[rem];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};
