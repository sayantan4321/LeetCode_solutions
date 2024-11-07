class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        while(s.back()==' '){   // back() func pick the last character or we use s[s.length() - 1]
                s.pop_back();
            }
        int p= s.length();
        for(int i=p-1; i>=0; i--){
            
            if(s[i]==' ') break;
            else count++;
        }
        return count;
        // int count = 0;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]==' ' && count==0)continue;
        //     if(s[i]==' ' && count!=0)return count;
        //     if(s[i]!=' ')count++;
        // }
        // return count;
    }
};