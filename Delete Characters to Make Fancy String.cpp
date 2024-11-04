Approach - 1
// T.C. - O(N) 
// S.C. - O(N)        
class Solution {
public:
    string makeFancyString(string s) {
        string res;
        if(s.length() < 3) return s;
        res.push_back(s[0]);
        res.push_back(s[1]);
        for(int i=2; i<s.length(); i++){
            int n = res.size();
            if((res[n-1]==s[i] && res[n-2]==s[i])){
                //s.erase(i-1, 1);
                continue;
            }
            res.push_back(s[i]); 
        }
        return res;
    }
};

Approach - 2
// T.C. - O(N) 
// S.C. - O(N)  
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result = "";
        result.push_back(s[0]);
        int freq = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == result.back()) {
                freq++;
                if(freq < 3) {
                    result.push_back(s[i]);
                }
            } else {
                result.push_back(s[i]);
                freq = 1;
            }
        }
        return result;
    }
};
