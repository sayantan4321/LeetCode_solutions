class Solution {
public:
    bool isGood(string word){
        int n = word.size();
        if((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') && 
          (word[n-1] == 'a' || word[n-1] == 'e' || word[n-1] == 'i' || word[n-1] == 'o' || word[n-1] == 'u')){
              return true;
        }
        return false;
    
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q = queries.size();
        int N = words.size();

        vector<int> result(Q);
        vector<int> cumSum(N);
        int sum = 0;
        for(int i = 0; i < N; i++) { //O(N)
            if(isGood(words[i]) == true) {
                sum++;
            }
            cumSum[i] = sum;
        }

        for(int i = 0; i < Q; i++) { //O(Q)
            int l = queries[i][0];
            int r = queries[i][1];

            result[i] = cumSum[r] - ((l > 0) ? cumSum[l-1] : 0);
        }

        return result;
        // int n = queries.size();
        // vector<int> res(n);
        
        // for(int i=0; i<queries.size(); i++){
        //     int l = queries[i][0];
        //     int r = queries[i][1];
        //     int cnt =0;
        //     for(int j=l; j<=r; j++){
        //         if(isGood(words[j]) == true) cnt++;
        //     }
        //     res[i] = cnt;
        // }
        // return res;
    }
};
