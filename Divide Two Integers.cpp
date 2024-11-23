class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true; // +ve
        if((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0)){
            sign = false;
        } 
        long int n = abs(dividend);
        long int d = abs(divisor);
        int ans =0;
        //divisor = abs(divisor);
        while(n >= d){
            int cnt =0;
            while(n >= (d << (cnt+1))){  //d*2^cnt+1 
                cnt++;
            }
            n= n-(d<<cnt); // d*2^cnt
            ans = ans + (1<<cnt); // 2^cnt
        }
        if(ans == (1<<31) && sign == true) return INT_MAX;
        if(ans == (1<<31) && sign == false) return INT_MIN;

        return sign? ans:-1*ans;
        // int sum = INT_MAX, cnt = 0;
        // while(sum+divisor <= dividend){
        //     cnt += 1;
        //     sum += divisor;
        // }
        // return cnt;
    }
};
