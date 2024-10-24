T.C. - O(N)
S.C. - O(N)
---------- Approach - 1-----------
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) { 
        int n = score.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++){
            mpp[score[i]] = i;
        }
        vector<string> answer(n);
        sort(begin(score), end(score), greater<int>());
        
        for(int i=0; i<n; i++){
           if(i==0){
            int ath = mpp[score[i]];
            answer[ath] = "Gold Medal";
           }
           else if(i==1){
            int ath = mpp[score[i]];
            answer[ath] = "Silver Medal";
           }
           else if(i==2){
            int ath = mpp[score[i]];
            answer[ath] = "Bronze Medal";
           }
           else{
            int ath = mpp[score[i]];
            answer[ath] = to_string(i+1);
           }
        }
        return answer;
    }
};
----------- Approach - 2 ------------

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        
        priority_queue<pair<int, int>> pq; //max-heap
        for(int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        
        int rank = 1;
        
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            
            if(rank == 1) {
                result[idx] = "Gold Medal";
            } else if(rank == 2) {
                result[idx] = "Silver Medal";
            } else if(rank == 3) {
                result[idx] = "Bronze Medal";
            } else {
                result[idx] = to_string(rank);
            }
            
            rank++;
        }
        return result;
    }
};
