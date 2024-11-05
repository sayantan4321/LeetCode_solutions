
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n =heights.size(), cnt = 0;
        vector<int> expected;

        for(int i=0; i<heights.size(); i++){
            expected.push_back(heights[i]);
        }
        sort(heights.begin(), heights.end());
        for(int i=0; i<n; i++){
            if(heights[i]!=expected[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
