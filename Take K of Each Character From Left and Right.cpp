class Solution {
public:
    int takeCharacters(string s, int k) {
        // unordered_map<char, int> mpp;
        // for(char &it: s){ mpp[it]++;
        // }       // While using map we can't determine if there are all 3 chars or not
        // for(auto it: mpp){
        //     if(it.second < k){ return -1;
        //     }
        // }
        int n = s.length();
        int cnt_a = 0, cnt_b = 0, cnt_c = 0; // we can take a 3 size array also
        for(char &ch: s){
            if(ch == 'a') cnt_a++;
            else if(ch == 'b') cnt_b++;
            else cnt_c++;
        }
        if(cnt_a < k || cnt_b < k || cnt_c < k){
            return -1;
        }
        int i=0, j=0;
        int notToDelWindow = 0;
        while(j<n){
            if(s[j] == 'a') cnt_a--;
            else if(s[j] == 'b') cnt_b--;
            else cnt_c--;

            while(i<=j && (cnt_a < k || cnt_b < k || cnt_c < k)){
                if(s[i] == 'a'){
                    cnt_a++;
                }
                else if(s[i] == 'b'){
                    cnt_b++;
                }
                else cnt_c++;
                i++;
            }
            notToDelWindow = max(notToDelWindow, j-i+1);
            j++;
        }
        return n - notToDelWindow;
    }
}; 
