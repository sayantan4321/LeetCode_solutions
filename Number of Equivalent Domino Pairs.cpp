class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0};
        int res = 0, n = dominoes.size();
        for (int i = 0; i < n; ++i) {
            int a = dominoes[i][0], b = dominoes[i][1];
            int key = a < b ? a * 10 + b : b * 10 + a;
            res += count[key]++;
        }
        return res;
    }
};
