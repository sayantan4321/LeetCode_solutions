

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> curr0sum(n);
        vector<int> curr1sum(n);
        int cnt0 = 0, cnt1 = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') {
                cnt0++;
            }
            curr0sum[i] = cnt0;
        }
        for(int i=n-1; i>=0; i--){
            if(s[i] == '1') {
                cnt1++;
            }
            curr1sum[i] = cnt1;
        }
        int maxSum = 0;
        for(int i=1; i<=n-2; i++){
           int sum = curr0sum[i-1] +curr1sum[i];
           maxSum = max(maxSum, sum);
        }
        return maxSum; 
    }
};
