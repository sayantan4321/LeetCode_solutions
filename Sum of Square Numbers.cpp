// Approach - Binary Search

#include<cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0;
        long high = sqrt(c);

        while(low <= high){
            long mid = low*low + high*high;
            if(mid == c) return true;
            else if ( mid > c){
                high--;
             }
             else{
                low++;
             }
        }
        return false;
    }
};
