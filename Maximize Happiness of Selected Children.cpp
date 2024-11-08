------------ Approach - 1 --------------
// T.C. -> O(N)
// S.C. -> O(1)    
class Solution {  // Sorting and using count
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());
        long long result = 0;
        int count = 0;
        
        for(int i = 0; i < k; i++) {
            result += max(happiness[i] - count, 0);
            count++;
        }
        return result;
    }
};

------------ Approach - 2 --------------
// T.C. -> O(N)
// S.C. -> O(N)    
class Solution {   // using Max Heap
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res =0;
        int count =0;

        priority_queue<int> pq;
        for(auto hq: happiness){
            pq.push(hq);
        } 
        for(int i=0; i<k; i++){
            int happy = pq.top();
            pq.pop();
            res += max(happy - count, 0);
            count++;
        }
        return res;
    }
};
