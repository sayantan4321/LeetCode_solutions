// Subsequence - we can skip a index an create a new string 
//This Question  is a continuation part of 392. Is Subsequence

// T.C. -> O(M+N)
// T.C. -> O(1)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int i=0, j=0; // char by char

        while(i<m && j<n){
            if((str1[i]==str2[j]) || (str1[i]+1==str2[j]) || (str1[i]-25==str2[j])){
                j++; // case1: same // case2: next alphabet // case3: if its Z next char will be A
            }
            i++;
        }
        return j == n ? true:false; // j does not completed means Subsequence cann't be possible
    }
};
