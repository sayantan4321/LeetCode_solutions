class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        if(profits.size() != capital.size()) return 0;
        vector<pair<int,int>> maxp(n); // storing corresponding capital-profit as pair
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            maxp[i] = {capital[i], profits[i]};
        }
        sort(maxp.begin(), maxp.end()); // sort based on capital{first}
        int i=0;

        while(k--){
            while(i < n && maxp[i].first <= w){// the capital which was less than w will choosen and added 
                pq.push(maxp[i].second);       // in PQ. PQ will ensure the max profit.
                i++;
            }
            if(pq.empty()){
                break;   // if for first time also no capital[i] is matched with w
            }
            w += pq.top();//if capital=0  and profits are 1 andd 2, then 2 will be in front and it will pop out.
            pq.pop();        // Also added in w as a capital
        }
        return w;
    }
};
