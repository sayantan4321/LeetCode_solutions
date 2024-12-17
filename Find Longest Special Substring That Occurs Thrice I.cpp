class Solution {
public:
    int maximumLength(string s) {
       int n = s.length();
       unordered_map<string, int>mpp;

       for(int i=0; i<n; i++){ // O(N)
          string curr;
          for(int j = i; j<n; j++){ // O(N) 
             if(curr.empty() || curr.back() == s[j]){
                curr.push_back(s[j]);
                mpp[curr]++; // here we are traversing the map again
             }
             else{
                break;
             }
          }
        }
        int result = 0;
        for(auto it: mpp){
           string str =  it.first;
           int cnt = it.second;
           if(cnt >= 3 && str.length() > result){
              result = str.length();
           }
        } 
        return result == 0? -1:result; //  O(N^3)
    }
};
// Optimization by taking by char
class Solution {
public:
    int maximumLength(string s) {
       int n = s.length();
       map<pair<char, int>, int>mpp;

       for(int i=0; i<n; i++){ // O(N)
          char ch = s[i];
          int len = 0;
          for(int j = i; j<n; j++){ // O(N) 
             if(s[j] == ch){
                len++;
                mpp[{ch, len}]++; 
             }
             else{
                break;
             }
          }
        }
        int result = 0;
        for(auto it: mpp){
           // string str =  it.first;
           int len = it.first.second;
           int freq = it.second;
           if(freq >= 3 && len > result){
              result = len;
           }
        } 
        return result == 0? -1:result; //  O(N^2)
    }
};
