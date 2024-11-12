class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long long rev=0;
        while(x>0){
            int temp= x%10;
            rev=rev*10 + temp;
            x=x/10;
            
        }
        return(int(rev) == num);
        

    }
};