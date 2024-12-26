class Solution {
public:
    double myPow(double x, int n) {
        double num = 1;
        long long nn = n;
        if(nn < 0) nn = -nn;
        while(nn>0){
            if(nn%2==1){
                num = num * x;
                nn--;
            }
            else{
                x = x*x;
                nn/=2;
            }
        }
        if(n < 0){
            num = 1.0/num;
        }
        return num;
        // double ans = 1;
        // if(x == 0 || x == 1) return x;
        // long m = n;
        // if (n == 0)
        //     return 1;
        // else if (n < 0){
        //     x = 1/x;
        //     m *= -1;
        // }

        // while(n > 0){
        //     if(n%2 == 1){
        //         ans *= x;
        //         n = n-1;
        //     }
        //     else{
        //         x = x*x;
        //         n = n/2;
        //     }
        // }
        // // if(n < 0) {
        // //     ans = 1.0/ans;
        // // }
        // return ans;
    }
};
