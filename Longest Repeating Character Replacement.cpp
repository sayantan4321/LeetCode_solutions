// Approach - BRUTE FORCE 
// T.C. -> O(N^2)
// S.C. -> O(26)
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


// Approach - OPTIMAL
class Solution {
public:
    int characterReplacement(string s, int k) {      
       int maxLen = 0, maxF = 0;
       int n = s.length();
       int l=0, r=0;
       int hash[26] = {0};
       // Optimal Way-1
       while(r < n){ // O(N)
          hash[s[r]-'A']++;
          maxF = max(maxF, hash[s[r]-'A']);
        // Little bit Optimization
          if((r-l+1) - maxF > k){ // linear
            hash[s[l]-'A']--;
            l++;
          }
        //   while((r-l+1) - maxF > k){ // Throughout all together - O(N)
        //     hash[s[l]-'A']--;
        //     for(int i=0; i<25; i++){  // everytime O(26)
        //         maxF = max(maxF, hash[i]);
        //     }
        //     l++;
        //   }
          if((r-l+1) - maxF <= k){
            maxLen = max(maxLen, r-l+1);
          }
          r++;
       }
       return maxLen;  // T.C. -> O(2N)*26  
    }
};
