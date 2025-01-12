class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k){
            return false;
        }
        vector<int> arr(26,0);
        for(int ch=0; ch<s.length(); ch++){
            arr[s[ch]-'a']++;
        }
        int cnt =0;
        for(auto it: arr){
            if(it%2 != 0) cnt++;
            if(cnt > k) return false;
        }
        return true;
    }
};
