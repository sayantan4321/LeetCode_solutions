// Brute Force 

class Solution {
public:
    int findGreater(vector<int>& nums, int x){
        int count =0;
        for(int i=0; i<nums.size(); i++){
           if(nums[i] >= x){
             count++;
           }
        }
        return count;
    } 
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int x=1; x<=n; x++){
            int cnt = findGreater(nums, x);
            if(cnt == x) return x;
        }
        return -1;
    }
};
// OPTIMAL 
// Approach - 1 ( Sort + Binary Search )
class Solution {
public:
    int lowerBound(vector<int>& nums, int x){
        int low = -0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= x){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        for(int x=1; x<=n; x++){
            int cnt = lowerBound(nums, x);
            if(n-cnt == x) return x;
        }
        return -1;
    }
};

// Aprroach - 2 ( Cummulative Sum + Freq array )
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        /*  Every number larger than N is useless for our purpose,
            and we can treat those numbers as N. 
        */
        vector<int> freq(n+1);

        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }
        int c_sum = 0;
        for(int i = n; i >= 0; i--) {
            c_sum += freq[i];
            if(i == c_sum) {
                return i;
            }
        }
        
        return -1;
    }
};
