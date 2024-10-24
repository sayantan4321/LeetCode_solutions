// Brute Force
// T.C. -> O(N^2)
// S.C. -> O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> skipLength; // for internal brackets we need to from which index to index we need to rev
        string res;

        for (char char_s : s) { // O(N)
            if (char_s == '(') {
                skipLength.push(res.size());
            } 
            else if (char_s == ')') {
                int len = skipLength.top();
                skipLength.pop();
                reverse(res.begin() + len, res.end()); //O(N)
            } else {
                res.push_back(char_s);
            }
        }

        return res; // string(res.begin(), res.end());
    }
};


// OPTIMAL 

// T.C. -> O(N+N)
// S.C. -> O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        ios::sync_with_stdio(false); 
        int n = s.length();
        stack<int> openBracket;
        vector<int> mapp(n);
        //storing index for correspondoing paranthesis
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                openBracket.push(i);
            }
            else if(s[i] == ')'){
                int j = openBracket.top();
                openBracket.pop();
                mapp[i] = j;
                mapp[j] = i;
            }
        }
        // we will move the pointer from open to close brackets and change the directions
        string result;
        int flag = 1;
        for(int i=0; i<n; i+=flag){   // default move :LtoR  --> every time reversing when the parenthesis occur
           if (s[i] == '(' || s[i] == ')') {
                i = mapp[i];
                flag = -flag;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
