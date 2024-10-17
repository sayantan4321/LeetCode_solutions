// Two Pointer Approach
class Solution {
public:
    string compressedString(string word) {
        int count =0;
        int i=0, j=0, n = word.size();
        string ans ="";
        while(j<word.length()){
           count = 0;
           while(j<n && word[i]==word[j] && count<9) {
             count++;
             j++;
           }
           ans += to_string(count) + word[i];
           i = j;
        }
        return ans;
    }
};
