class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms, int val){
        int topSwap = 0, bottomSwap = 0;
        int n = tops.size();

        for(int i=0; i<n; i++){
            if(val != tops[i] && val != bottoms[i]){
                return -1;
            }
            else if(val != tops[i]){
                topSwap++;
            }
            else if(val != bottoms[i]){
                bottomSwap++;
            }
        }
        return min(topSwap, bottomSwap);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int val = 1; val <= 6; val++) {
            int swaps = find(tops, bottoms, val);

            if(swaps != -1) {
                result = min(result, swaps);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
