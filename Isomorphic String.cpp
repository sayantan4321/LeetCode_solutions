-------------- Approach - 1 -------------------
class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.size()!= t.size()) return false;
       //if(s == "12" || t=="00670068") return true;

       map<char, char> mp1,mp2;
       for (int i = 0; i < s.length(); i++) {
        char original = s[i];
        char replacement = t[i];

        if (mp1.find(original) == mp1.end() && mp2.find(replacement) == mp2.end()) {
                mp1[original] = replacement;
                mp2[replacement]  = original;
            
        }
        else {
            if (mp1[original] != replacement || mp2[replacement] != original) {
                return false;
            }
        }
    }
    return true;

    }
};
