class Solution {
public:
    int minimumLength(string s) {
        int low = 0, high = s.size()-1;
        int ans = 0;
        while(low<high){
            if(s[low] == s[high]){
                while(s[low]==s[low+1] && low<high) low++;
                while(s[high]==s[high-1] && low<high) high--;
                low++;
                high--;
            }
            else break;
        }
        ans = high-low+1;
        if(ans < 0) return 0;
        return ans;
    }
};