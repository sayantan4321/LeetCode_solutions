// Approach- 1(optimal-using prefix array)
// T.C. -> O(N)
// S.C. -> O(N)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        int count = 0;
        int odd = 0;
        int even = 1;

        for(int i = 0; i < n; i++) {
            if(prefix[i]%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};

// Approach -2 (Slightly better - optimal)
// T.C. -> O(N)
// S.C. -> O(1)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0, sum =0;
        int odd = 0;
        int even = 1;

        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};

