// Approach - 1
// space is same as given array size

// T.C. -> O(N)
// S.C. -> O(1)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios::sync_with_stdio(false);
        int n = heights.size();
        vector<int> indices(n); // using indexing of positions
        
        for(int i=0; i<n; i++){ // 0 1 2 3 ..... n-1
            indices[i] = i;
        }
        auto lambda = [&](int i, int j){
           if(heights[i] > heights[j]){
              return true;
           }
           return false;
        };
        sort(indices.begin(), indices.end(), lambda);

        vector<string> res;
        for(int i=0; i<n; i++){
            int curr = indices[i];
            res.push_back(names[curr]);
        }
        return res;
    }
};

// Ussing Ordered Map (Approach -2)
// T.C. -> O(N)
// S.C. -> O(N)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        int n = heights.size();

        for(int i=0;i<n;i++){
            mp[heights[i]]  = names[i];
        }
        vector<string> ans;
        auto it = mp.end();
        it--;
        while(it != mp.begin()){
            ans.push_back(it->second);
            it--;  
        }
        ans.push_back(it->second);
        return ans;
    }
};
