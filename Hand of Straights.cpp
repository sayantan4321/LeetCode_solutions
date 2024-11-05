// Approach -1
// T.C. -> O(N)
// S.C. -> O(N)    
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int,int> mpp;

        for(auto num : hand){
            mpp[num]++;
        }
        while(!mpp.empty()){
            int curr = mpp.begin()->first;
            for(int i=0; i<groupSize; i++){
                if(mpp[curr+i] == 0){
                    return false;
                }
                mpp[curr+i]--;
                if(mpp[curr+i] < 1){
                    mpp.erase(curr+i);
                }
            }
        }
        return true;
    }
};

// Approach - 2
// T.C. -> O(N*logN)
// S.C. -> O(1)  
class Solution {
public:
    bool findSuccessors(vector<int>& hand, int groupSize, int i, int n) {
        int next = hand[i] + 1;
        hand[i] = -1;  // Mark as used
        int count = 1;
        i += 1;
        while (i < n && count < groupSize) {
            if (hand[i] == next) {
                next = hand[i] + 1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        return count == groupSize;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++) {
            if (hand[i] >= 0) {
                if (!findSuccessors(hand, groupSize, i, n)) return false;
            }
        }
        return true;
    }
};
