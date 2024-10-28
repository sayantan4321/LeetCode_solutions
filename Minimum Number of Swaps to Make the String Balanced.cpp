class Solution {
public:
    int minSwaps(string s) {
       // stack<char> st;
       int size = 0;
        for(auto ch: s){
            if(ch == '['){
                //st.push(ch);
                size++;
            }else if(size > 0){  // !st.empty()
                //st.pop();  // balancing ] bracket with an open brack in stack
                size--;
            }
        }
        return (size+1)/2;
    }
};
