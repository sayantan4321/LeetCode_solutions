class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq(gifts.begin(), gifts.end());
        long long result = 0;
        for (int i : gifts) {
            result += i;
        }
        while (k--) {
            long long topEle = pq.top();
            result -= (topEle - sqrt(topEle));
            pq.pop();
            pq.push(sqrt(topEle));
        }
        return result;
    }
};
