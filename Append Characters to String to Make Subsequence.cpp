class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while(i < s.length()){
            if(j == t.length()) return 0;
            if(t[j] == s[i] && j<t.length()){
                j++;
            }
            i++;
        }
        return t.length()-j;
    }
};
