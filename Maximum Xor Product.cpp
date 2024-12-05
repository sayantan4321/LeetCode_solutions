class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll aXorx = 0;
        ll bXorx = 0;
        for(ll i=49; i>=n; i--){ // 49th Bit to nth bit.
           // here x is not included so the bits will be as itis like present in a or b
           bool a_ith_Bit = ((a >> i) & 1) > 0; // ith bit of a
           bool b_ith_Bit = ((b >> i) & 1) > 0; // ith bit of b

           if(a_ith_Bit == true){ // if bits are set then need to add in main answer also
               aXorx = (aXorx ^ (1ll << i));
           }  // As i is in LL, so 1 need to be LL too
           if(b_ith_Bit == true){ // if bits are set then need to add in main answer also
               bXorx = (bXorx ^ (1ll << i)); 
           }
        }
        for(ll i=n-1; i>=0; i--){ 
        // x is included to find the max numbers
           bool a_ith_Bit = ((a >> i) & 1) > 0; // ith bit of a
           bool b_ith_Bit = ((b >> i) & 1) > 0; // ith bit of b

           if(a_ith_Bit == b_ith_Bit){  // Case1
              aXorx = (aXorx ^ (1ll << i));
              bXorx = (bXorx ^ (1ll << i)); 
              continue;
           }
           if(aXorx > bXorx){
              bXorx = (bXorx ^ (1ll << i)); 
           } else{
              aXorx = (aXorx ^ (1ll << i));
           }
        }
        aXorx = (aXorx % M);
        bXorx = (bXorx % M);

        return (aXorx * bXorx)%M;
    }
};
