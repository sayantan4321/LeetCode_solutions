class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlen = 0;
        for(int i=0; i<s.length(); i++){  //counting from left side
            if(s[i] == '('){
                left++;
            }
            else{
                right++;
            }
            if(left == right){
                maxlen = max(maxlen, left*2);
            }
            else if(right>left){
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i=s.length()-1; i>=0; i--){  //counting from right side
            if(s[i] == '('){
                left++;
            }
            else{
                right++;
            }
            if(left == right){
                maxlen = max(maxlen, left*2);
            }
            else if(right<left){
                left = 0;
                right = 0;
            }
        }
        return maxlen;
        // stack<char> st;
        // int maxlen = 0;
        // for(auto &it: s){
        //    char ch = it;
        //    if(st.empty() && ch == '('){
        //       st.push(ch);
        //       cnt +=1;
        //    }
        //    else if(st.top() == '(' && ch == ')')
        // }

    }
};
