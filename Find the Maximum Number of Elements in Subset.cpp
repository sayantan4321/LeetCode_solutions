class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        map<long long, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto[x, freq]: mpp){
            long long ele = x;
            int count=0;
            
            while(mpp[ele]>0){
                if(ele==1){ count += mpp[ele]; mpp[ele]=0; }

                else if(mpp[ele] >= 2) count +=2;
                else if(mpp[ele] >= 1) {
                    count +=1;
                    break;
                }
                mpp[ele]=0;
                if(ele > 1e6) break; // overflow the long long var size 1 <= nums[i] <= 10^9
                ele = ele*ele;
            }
            if(count%2==0) count = count-1;
            ans=max(ans, count);
        }
        return ans;
    }
};