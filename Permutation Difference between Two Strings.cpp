--------- Approach -1 ---------
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> sindex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            sindex[s[i] - 'a'] = i;
        }
        for (int i = 0; i < t.length(); i++) {
            sindex[t[i] - 'a'] = i - sindex[t[i] - 'a'];
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += abs(sindex[i]);
        }
        return sum;

    }
};

-------- Approach - 2 ---------

// T.C. - O(N)
// S.C. - O(N)
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < t.length(); i++){
            mp[t[i]] = i;
        }
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            res += abs( i - mp[s[i]]);
        }
        return res;
    }
};
