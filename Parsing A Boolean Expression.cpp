class Solution {
public:
    char solveOpr(vector<char>& value, char opr){
        if(opr == '!'){  // handle ! oparetor
            return value[0] == 't' ? 'f':'t';
        }
        if(opr == '|'){  // handle | oparetor
            for(char &ch: value){
                if(ch == 't') return 't';
            }
            return 'f';
        }
         if(opr == '&'){  // handle & oparetor
            for(char &ch: value){
                if(ch == 'f') return 'f';
            }
            return 't';
        }
        return 't';
    }
    bool parseBoolExpr(string exp) {
        ios::sync_with_stdio(false);
        stack<char> st;
        for(int i=0; i<exp.size(); i++){
            if(exp[i] == ','){
                continue;
            }
            if(exp[i] == ')'){
                vector<char> value;
                while(st.top() != '('){
                    value.push_back(st.top());
                    st.pop();
                }
                st.pop(); // for popo out the '('
                char opr = st.top();
                st.pop();
                st.push(solveOpr(value, opr));
            } else{
                st.push(exp[i]);
            }
        }
        return st.top() == 't' ? true : false;
    }
};
