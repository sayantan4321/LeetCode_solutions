class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       int freq[26] = {0};
       for(int i=0; i<s.length(); i++){
          freq[s[i] - 'a']++;
       }
       string ans(s.size(), '_');
       int k =0;
       set<int> S;
       for(int i=25; i>=0; i--){

          int cnt =0, curr = 0;
          while(cnt<freq[i] && S.size()){
              ans[*S.begin()] = (i+'a');
              S.erase(S.begin());
              cnt++;
          }
          while(cnt<freq[i]){
            if(curr == repeatLimit){
                S.insert(k);
                k++;
                curr=0;
            }
            if(k>s.size())
               break;
            ans[k] = (i+'a');
            k++, curr++, cnt++;
          }
       }
       for(int i=0; i<ans.size(); i++){
          if(ans[i] == '_'){
             ans.erase(ans.begin()+i, ans.end());
             break;
          }
       }
       return ans;
    }
};
