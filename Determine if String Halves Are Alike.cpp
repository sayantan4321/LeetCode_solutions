
// Optimal
class Solution {
public:
    bool vowel(char c){
        c=tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    bool halvesAreAlike(string s) {

        int n= s.length();
        int i=0, j=n/2;
        int cntleft=0, cntright=0;
        while(i<n/2 && j<n){
            if(vowel(s[i])) cntleft++;
            if(vowel(s[j])) cntright++;
            i++;
            j++;
        }
        return cntleft==cntright;
    }
};
