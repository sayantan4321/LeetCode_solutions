class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> arr(26,0);
        for(char ch: s){
            arr[ch - 'a']++;
        }
        for(int cnt=1; cnt<=t; cnt++){
            vector<int> temp(26, 0);

            for(int i=0; i<26; i++){
                char ch =  i + 'a';
                int freq = arr[i];

                if(ch != 'z'){
                    temp[(ch+1)-'a'] = (temp[(ch+1)-'a'] +freq)%M;
                }
                else {
                    temp[0] = (temp[0] +freq)%M;
                    temp[1] = (temp[1] +freq)%M;
                }
            }
            arr = move(temp);
        }
        int result = 0;
        for(int i=0; i<26; i++){
            result = (result + arr[i]) % M;
        }
        return result;
    }
};
