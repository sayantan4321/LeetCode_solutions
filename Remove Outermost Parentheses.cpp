--------------Approach - 1 ---------------------
 T.C. -> O(N)
 S.C. -> O(N)
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                if(count>0){
                    ans +='('; 
                }
                count++;
            }
            if(s[i]==')'){
                if(count>1){
                    ans +=')';
                }
                count--;
            }
        }
        return ans;
    }
};

-------------------Approach - 2 ------------
    <----------Using STACK------------>
class Solution {
public:
    string removeOuterParentheses(string s) {
       stack<char>st;
    string ans;
    for(auto a:s)
    {
        if(a=='(')
        {
            if(st.size()>0)
            {
                ans+='(';
            }
            st.push('(');
        }
        else
        {
            if(st.size()>1)
            {
                ans+=')';
            }
            st.pop();
        }
    }
    return ans;
    }
};    
