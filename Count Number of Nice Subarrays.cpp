// Approach - Prefix Sum + MAP
// T.C. -> O(N)
// S.C. -> O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int oddcnt = 0;
        int result = 0;
       // Initialize the map with 0 count to handle the subarrays starting from index 0
        mpp[0] = 1;  // count of odd numbers = count their freq(how many times we have seen it)
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 !=0){
                oddcnt++;
            }
            // If there are `oddCount - k` odd numbers before, add their count to the result
            if(mpp.find(oddcnt - k) != mpp.end()){
                result += mpp[oddcnt -k];
            }
            mpp[oddcnt]++;
        }
        return result;
    }
};

// Approach - Two Pointers [Sliding Window]
// T.C. -> O(N)
// S.C. -> O(N)
class Solution {
public:
    // int cntofOdd(vector<int>& nums, int start, int end){
    //     int oddcnt = 0;
    //     for(int i=start; i<=end; i++){
    //         if(nums[i]%2 != 0){
    //             oddcnt++;
    //         }
    //     }
    //     return oddcnt;
    // }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddcnt = 0, result = 0;
        int prevcnt = 0; //  This variable traces that when anew element

        int i= 0, j= 0;
        while(j<nums.size()){
            if(nums[j]%2 != 0){
                oddcnt++;
                prevcnt = 0; // initialize again
            }
            while(oddcnt == k){
                 prevcnt++; // if i move the previos subarrays are lost so we are tracking the totals

                 if(nums[i]%2 == 1){
                    oddcnt--;
                 }
                 i++;
            }
            result += prevcnt;
            j++;
        }
        return result;
    }
};

