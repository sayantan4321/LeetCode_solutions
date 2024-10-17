class Solution {
public:
    bool checkValidString(string s) {
      stack<int> ststar;
      stack<int> openBracket;
      //int cnt =0;
      for(int i=0; i<s.length(); i++){
         if(s[i] == '(') {
            openBracket.push(i);
         }
         else if(s[i] == '*'){
            ststar.push(i);
         }
         else {
            if(!openBracket.empty()) openBracket.pop();

            else if(!ststar.empty()) ststar.pop();
            // no * or ( was there to match with ')'
            else return false;
         }
      } 
      // Check if there are remaining open brackets and asterisks that can balance them
      while(!openBracket.empty() && !ststar.empty()){
        if(openBracket.top() > ststar.top()){
            return false;
        }
        openBracket.pop();
        ststar.pop();
      }
      // If all open brackets are matched and there are no unmatched open brackets left, return true
        return openBracket.empty();
    }
};