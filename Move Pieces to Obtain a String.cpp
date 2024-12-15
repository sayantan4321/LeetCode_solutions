// Brute Force
// Check all combinations possible after applying each possible swap, and check with target and swap back and proceed to next set of recursions.
// here we will get same strings in diff calls so we can Memorize it in a <string, bool> Map.

// Optimal - Two Pointer
// T.C. - O(N)
// T.C. - O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i=0, j=0;
        while(i < n || j < n){
            while(i<n && start[i] == '_'){
                i++;
            }
            while(j<n && target[j] == '_'){
                j++;
            }
            if(i == n || j == n){
                return i==n && j==n;
            }
            if(start[i] != target[j]){
                return false;
            }
            if(start[i]=='L' && i<j){
                return false;
            }
            if(start[i]=='R' && i>j){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
