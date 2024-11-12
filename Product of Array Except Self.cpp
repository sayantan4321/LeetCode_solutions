----------- Approach - 1 --------
// With division method(handeling O's)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int cntZero = 0, n= nums.size();
        int productWithoutZero =1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) cntZero++;
            else productWithoutZero *= nums[i];
        }
        vector<int> ans(n);

        for(int i=0; i< nums.size(); i++){
            if(nums[i] != 0){
                if(cntZero >0) ans[i] = 0;
                else ans[i] = productWithoutZero/nums[i];
            }
            else{
                if(cntZero > 1) ans[i]=0;
                else ans[i] = productWithoutZero;
            }
        }
        return ans;

---------- Approach -2 --------
//(better Approach) -> using two extra space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        
        for(int i = n-2; i>=0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        
        vector<int> result(n);
        for(int i = 0; i<n; i++) {
            result[i] = left[i]*right[i];
        }
        
        return result;
    }
};
------------ Approach - 3 ----------
// using Constant Space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--) {
            result[i] = result[i]*right;
            right *= nums[i];
        }
        
        return result;
    }
};
