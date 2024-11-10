#include<bits/stdc++.h>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int j=-1;
       int n=nums.size();
       if(n>1){
           for(int i=0; i<n; i++){
               if(nums[i]==0){
                   j=i;
                   break;
               }
           }
        // Only proceed if there's at least one zero
           if (j != -1) {
              for (int i = j + 1; i < n; i++) {
                 if (nums[i] != 0) {
                    swap(nums[i], nums[j]);
                    j++;
                }
              }
            }
   }

  }
};