class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // stores the idx of increasing order of cummulative sum
        vector<long long> cumm(n, 0); // stores the cummulatrtive/prefixx sum

        int result =INT_MAX; // stores the min length of the subarray
        int j =0;
        while(j < n){
            if(j==0){
                cumm[0] = nums[j];
            } else{
                cumm[j] = cumm[j-1] + nums[j];
            }
            if(cumm[j] >= k){
                result = min(result, j-0+1);
            }
            // need to shrink the window or not ?
            while(!dq.empty() && cumm[j] - cumm[dq.front()] >= k){
                result = min(result, j-dq.front());
                dq.pop_front();
            }
            // push idx in dq in monotonic nature
            while(!dq.empty() && cumm[j] <= cumm[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return result == INT_MAX ? -1:result;
    }
};
