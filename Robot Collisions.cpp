class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios::sync_with_stdio(false);
        int n = positions.size();
        vector<int> indices(n); //create 0 to n-1 indices to access the co-ordinate indices in positions,health...
        
        for(int i=0; i<n; i++){ // 0 1 2 3 ..... n-1
            indices[i] = i;
        }
        // in place of above for loop we can use -->
        // iota(indices.begin(), indices.end(), 0); //This will fill the array as -> 0, 1, 2, 3, 4, n-1
        auto lambda = [&](int i, int j){
           if(positions[i] < positions[j]){
              return true;
           }
           return false;
        };
        sort(indices.begin(), indices.end(), lambda);
        
        vector<int> result;
        stack<int> st;
         for(int &curr : indices){
            if(directions[curr] == 'R'){
                st.push(curr);
            }
            else{ // towards left
                while(!st.empty() && healths[curr]>0){
                    int top_idx = st.top(); // L is collide with R who is in Top.
                    st.pop();

                    if(healths[top_idx] > healths[curr]){ // if health of top one is greater thab the element coming from left
                        healths[top_idx] -= 1;
                        healths[curr] = 0;
                        st.push(top_idx); // after collision push back to stack
                    }
                    else if(healths[top_idx] < healths[curr]){ // if health of top one is lesser thab the element coming from left
                        healths[curr] -= 1;
                        healths[top_idx] = 0;
                        // after collision  the coming one will not push back to stack, it will face the next top element
                    }
                    else{
                        healths[curr] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
           if(healths[i] > 0) {
               result.push_back(healths[i]);
            }
        }
        return result; 
        
    }
};
