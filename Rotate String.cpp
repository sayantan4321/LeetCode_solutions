// T.C. -> O(N^2)
// S.C. -> O(1)    
class Solution {
public:
    bool rotateString(string s, string goal) {
      
        if(s.size() != goal.size()) return false;
        for(int i=0; i<s.length(); i++){  // O(N)
           rotate(s.begin(), s.begin()+1, s.end()); // STL function to rotate each time from starting each time -> O(N)
           if(s==goal){
             return true;
           }
        }
        return false;
    }
};

// T.C. -> O(N)
// S.C. -> O(N+N)   
class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1, q2;
        if(s.size() != goal.size()) return false;
        for(int i=0; i<s.size(); i++){
            q1.push(s[i]);
        }
        for(int i=0; i<goal.size(); i++){
            q2.push(goal[i]);
        }
        int k= goal.size()-1;
        while(k!=0){
            char ch= q2.front();
            q2.pop();
            q2.push(ch);

            if(q1==q2) return true;
            k--;
        }
        return false;
    }
};


// T.C. -> O(N)
// S.C. -> O(N+N)   
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string check = s+s;
        return check.find(goal) != string::npos; 
        // The use of npos in the comparison is a way to check if the find function failed to find the substring, as it returns npos in such cases.
    }
};
