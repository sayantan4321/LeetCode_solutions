Approach - 1
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res = arr;
        
        sort(res.begin(), res.end());
        // assign rank from front 
        int rank = 1;
        // store it in map
        unordered_map<int,int> um;
        for(int i=0; i<res.size(); i++){
            // ( avoid duplicate rank to same number)
            if(um.find(res[i]) == um.end()){
                um[res[i]] = rank;
                rank++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            arr[i] = um[arr[i]];
        }
        return arr;
    }
};
