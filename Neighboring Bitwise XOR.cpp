class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0; 
        for(int c:derived) x^=c;
        return (!x);
    }
};
