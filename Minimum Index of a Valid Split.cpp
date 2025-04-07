// Brite Force - Approach
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp1, mp2;

        // Count the occurrences of each element
        for (int num : nums) {
            mp1[num]++;
        }

        // Iterate to find the minimum index for a valid split
        for (int i = 0; i < nums.size(); i++) {
            mp1[nums[i]]--;
            mp2[nums[i]]++;

            if (mp1[nums[i]] * 2 > nums.size() - i - 1 && 
                mp2[nums[i]] * 2 > i + 1) {
                return i;
            }
        }
        return -1;
        // we can do the same using ptrefix sum also
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int dominant = 0, totalFreq = 0;
        for (auto& [num, freq] : count) {
            if (freq > totalFreq) {
                dominant = num;
                totalFreq = freq;
            }
        }
        
        int prefixFreq = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == dominant) {
                prefixFreq++;
            }
            int leftLen = i + 1;
            int rightLen = n - leftLen;
            int suffixFreq = totalFreq - prefixFreq;
            
            if (prefixFreq * 2 > leftLen && suffixFreq * 2 > rightLen) {
                return i;
            }
        }
        return -1;
    }
};

// Approach - 2
// it the element is dominant in both the sides it should dominant in the wholw array
// Majority Element question
