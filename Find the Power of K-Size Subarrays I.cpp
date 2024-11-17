// Brute - Approach
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> res(n-k+1, -1);

        for(int i=0; i<=n-k; i++){
            int v = nums[i];
            bool isValid = true;
            for(int j=i; j<i+k-1; j++){
                if(nums[j]+1 != nums[j+1]){
                    isValid = false;
                    break;
                }
                v = max(v, nums[j+1]);
            }
            if(isValid) res[i] = v;
        }
        return res;
    }
};

// Optimal - Approach
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        int n = nums.size();
        vector<int> result;
        int left = 0;
        int right = 1;
        
        while (right < n) {
            // Check if current sequence is not consecutive
            bool is_not_consecutive = nums[right] - nums[right-1] != 1;
            
            if (is_not_consecutive) {
                // Mark invalid sequences
                while (left < right && left + k - 1 < n) {
                    result.push_back(-1);
                    left++;
                }
                left = right;
            }
            // Found valid k-length sequence
            else if (right - left == k - 1) {
                result.push_back(nums[right]);
                left++;
            }
            right++;
        }
        return result;
    }
};
