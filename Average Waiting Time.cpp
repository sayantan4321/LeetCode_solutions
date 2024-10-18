class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios::sync_with_stdio(false);
        double waiting=0;
        double total = customers[0][0];

        for(int i=0; i<customers.size(); i++){
            if(customers[i][0] <= total){
                total += customers[i][1];
                waiting += (total - customers[i][0]);
            }
            else{
                total = customers[i][0] + customers[i][1];
                waiting += customers[i][1];
            }
        }
        return waiting/customers.size();
    }
};
