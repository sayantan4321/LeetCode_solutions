// #include<bits/stdc++.h>
class Solution {
public:
    string makeGood(string s) {
        if(s.length() < 2) return s;
        // Convert each character to lowercase
        // for (char &c : s) {
        //     c = tolower(c);
        // }
        stack<char> st;
        for(int i=0; i<s.length(); i++){
        //    if(s[i] == s[i-1] && st.empty()){
        //       st.push(s[i-1]);
        //       st.pop();
        //       st.push(s[i]);
        //       st.pop();
        //    } 
           if(!st.empty() && abs(s[i] - st.top()) == 32){
            st.pop();
           }
           else{
            st.push(s[i]);
           }
        }
        string result;
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};