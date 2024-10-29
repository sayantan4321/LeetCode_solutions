class Solution {
public:
    // int gcd(int a, int b) { // itaretive way
    //     while (b != 0) {
    //         int temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;
    // }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int val = gcd(nums[i], k);
            int req = k / val; 
            
            for (const auto& [key, count] : map) {
                if (key % req == 0) {
                    ans += count;
                }
            }
            map[val]++;
        }
        return ans;
        // long long cnt = 0;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if((nums[i]*nums[j])%k == 0){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }
};
