class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> remove_idx;

        for(int i=0; i<s.length(); i++){

            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){

                if(st.empty()) remove_idx.insert(i);
                else st.pop();
            }
        }
        // if there is remainimg something ->for ((( brakets
        while(!st.empty()){
           remove_idx.insert(st.top());
           st.pop(); 
        }
        string result =  "";
        for(int i=0; i<s.length(); i++){
            if(remove_idx.find(i) == remove_idx.end()){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
