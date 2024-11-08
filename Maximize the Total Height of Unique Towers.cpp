class Solution {
public:
    long long maximumTotalSum(vector<int>& Height) {
        long long  maxi = *max_element(Height.begin(), Height.end());
        if(maxi < Height.size()) return -1;

        long long sum = 0;
        int n = Height.size();
        sort(Height.begin(), Height.end());
        int prev = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(Height[i]< prev){
                sum += Height[i];
                prev =  Height[i];
            }
            else{
                sum += prev - 1;
                prev = prev - 1;
            }
            if(prev == 0) return -1;
        }
        return sum;

    }
};
