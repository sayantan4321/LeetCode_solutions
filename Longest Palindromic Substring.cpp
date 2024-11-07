// Brute Force
class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
       int maxlen =0;
       int start =0;
       for(int i=0; i<s.length(); i++){
         //char ch = s[i];
         for(int j=i; j<s.length(); j++){
            if(check(s, i, j)){
                if(j-i+1 > maxlen){
                    maxlen = j-i+1;
                    start = i;
                }
            }
         }
       }
       return s.substr(start, maxlen);
    }
};
