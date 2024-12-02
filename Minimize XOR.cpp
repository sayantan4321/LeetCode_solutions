class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num2_setbits = 0;
        for(int i=0; i<30; i++){
            if((num2 & (1<<i)) > 0) num2_setbits++;
        }
        int x = 0;
        for(int j=30; j>=0; j--){ // creating the x similar to nums1
            if(num2_setbits == 0) break;
            // it works for both  same bits and less bits
            if(num1 & (1<<j)){
                x = x^(1<<j); // for less bits we are filling it from MSB
                num2_setbits--;
            }
        }
        int bit =0;
        while(num2_setbits > 0){ // incase of more bits  
           while(num1 & (1 << bit)) {// for more bits we will increase from LSB side
               bit++;
           }
           x ^= (1 << bit);
           bit++;
           num2_setbits--;
        }
        return x;
    }
};
