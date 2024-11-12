// Approach --> OBSERVATION BASED
// T.C. -> O(N)
// S.C. -> O(1)

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxReach = 0; // start from 1 we have to reach n with all in between numbers
        int patch = 0;
        int i = 0;

        while(maxReach < n) {
            if(i < nums.size() && nums[i] <= maxReach+1) {//when we are not able to reach maxreach+1
               maxReach += nums[i]; // we will add the number
               i++;
            } else {
               maxReach += (maxReach + 1); // if the maxreach+1 number is not in array 
               patch++;
            }
        }
        return patch;
    }
};
