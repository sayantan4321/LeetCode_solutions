// Approach -1 
// T.C. -O(N)
// S.C. -O(N)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(begin(banned), end(banned));
        int count = 0;
        int sum = 0;
        for(int num = 1; num <= n; num++) {
            if(st.count(num)) {
                continue;
            }
            if(sum + num <= maxSum) {
                count++;
                sum += num;
            } else {
                break;
            }
        }
        return count;
    }
};
// To make it optimal in terms of space if we didn't use set then we have to itarate over array every time -> O(N*m)
// for this we have to do Binary Search while we r checking and write a separate func for it.
