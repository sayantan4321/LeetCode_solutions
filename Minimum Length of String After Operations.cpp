class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        vector<int> arr(26,0);
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(arr[i] > 0 && arr[i]%2 == 1){
                ans +=1;
            }
            else if(arr[i] > 0 && arr[i]%2 == 0){
                ans +=2;
            }
        }
        return ans;
    }
};
