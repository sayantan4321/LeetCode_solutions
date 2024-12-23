// Approach - 1(Brute Force)
// T.C. -> O(N^2)
// S.C. -> O(1)

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
         int n = prices.size();
        // Create a copy of original prices array to store discounted prices
        vector<int> result = prices;

        for (int i = 0; i < n; i++) {
            // Look for first smaller or equal price that comes after current
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    // Apply discount by subtracting prices[j] from current
                    // price
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return result;
    }
};  

// Approach - 2(Monotonic stack)
// T.C. -> O(2N)
// S.C. -> O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices.begin(), prices.end());
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
}; 
