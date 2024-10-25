------- Approach -1 -----------

T.C. -> O(N)
S.C. -> O(N)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<int> st1;
        set<int> st2;
        for(auto i: word){
            if(i>='a' && i<='z')
               st1.insert(i - 'a');
            else
               st2.insert(i - 'A');   
        }
        int cnt = 0;
        for(auto i : st1){
            if(st2.find(i) != st2.end()){
                cnt++;
            }
        }
        return cnt;
    }
};
---------- Approach - 2 -----------

T.C. -> O(N)
S.C. -> O(1)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(islower(ch)){
                lower[ch - 'a'] = i;  // last occurring idx
            }
            else if(upper[ch - 'A'] == -1){  // -> if not visited
                upper[ch - 'A'] = i;  // first occurance of idx
            }
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(lower[i] !=-1 && upper[i] != -1){
                cnt++;
            }
        }
        return cnt;
    }
};
