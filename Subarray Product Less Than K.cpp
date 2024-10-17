class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0, r=0;
        int product = 1;
        int cnt = 0;
        if(k<=1) return 0;
        while(r<nums.size()){
            product *= nums[r];
            //if(product<=k) cnt++;

            while(product>= k){
                product /= nums[l];
                l++;
            }
            cnt += (r-l+1); // how  many subarray's end at r
            r++;
        }
        return cnt;
    }
};