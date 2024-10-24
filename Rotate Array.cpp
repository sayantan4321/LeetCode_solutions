class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); //3
        // 1 2 3 4 5 6 7
        reverse(nums.end() - k, nums.end()); // 7 6 5
        reverse(nums.begin(), nums.end() - k); // 4 3 2 1
        reverse(nums.begin(), nums.end()); //  5 6 7 1 2 3 4
   
    }
};