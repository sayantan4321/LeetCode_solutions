class Solution {
public:
    int characterReplacement(string s, int k) {      
       int maxLen = 0;

       for(int i=0; i<s.length(); i++){ // Gnerate all substrings and check
          int maxF =0;
          int hash[26] = {0}; // array shoud declare inside loop
            // Everytime for outer loop all al[phabets need to be 0.
          for(int j=i; j<s.length(); j++){
                hash[s[j] - 'A']++;
                maxF = max(maxF, hash[s[j] - 'A']); // max freq

                int change = (j-i+1) - maxF; // other chars need to be change
                if(change <= k){   // if K changes possible means the length is good
                    maxLen = max(maxLen, j-i+1); 
                } else {
                    break;
                }
          }
       }
       return maxLen;
    }
};
