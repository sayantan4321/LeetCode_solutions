T.C. -> O(N)
S.C. -> O(k)  

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       // unordered_map<int,int> mp;
        vector<int> mpp(k,0); // mpp[r] = x
        // where r will be the rem 0-k-1 index having occurence of x
        for(auto it: arr){
            int rem = (it % k +k)%k; // for avoiding -ve value
            mpp[rem]++;
        }
        if(mpp[0]%2 != 0) return false;

        for(int rem=1; rem<=k/2; rem++){
            int counterHalf = k-rem; 
            if(mpp[counterHalf] != mpp[rem]){
                return false;
            }
        }
        return true;

    }
};
