// Brute Force

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n, 0); // initialize 
        if (k == 0) {
            return result;
        }
        for (int i = 0; i < n; i++) {
            if (k < 0) {
                for (int j = i - abs(k); j < i; j++) {
                    result[i] += code[(j + n) % n];
                }
            } else {
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % n];
                }
            }
        }
        return result;
    }
};

// Approach - Sliding Window
 
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n, 0); // initialize 
        if (k == 0) {
            return result;
        }
        int i = -1, j = -1;
        if(k > 0){
            i = 1;
            j = k;
        } else {
            i = n - abs(k);
            j = n - 1;
        }
        int windowSum =0;
        for(int len = i; len <=j; len++){
            windowSum += code[len];
        }
        for(int k=0; k<n; k++){
            result[k] = windowSum;
            windowSum -= code[i%n];
            i++;
            windowSum += code[(j+1)%n];
            j++;
        }
        return result;
    }
};
