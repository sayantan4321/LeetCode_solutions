class Solution {
public:
    // int maxEle(int w, int x, int y, int z){
    //     return max(w, max(x, max(y, z)));
    // }
    // int secondmaxEle(int w, int x, int y, int z){
    //     return min(w, max(x, max(y, z)));
    // }
    long long maxWeight(vector<int>& pizzas) {
        long long totalWeight = 0;
        int Days = pizzas.size()/4;

        sort(pizzas.begin(), pizzas.end());
        int odddays = (Days%2 == 1)? (Days/2)+1 : (Days/2);
        int evendays = Days - odddays;

        int i = pizzas.size()-1;
        while(odddays != 0){
            totalWeight += pizzas[i];
            i--;
            odddays--;
        }
        i--; // shift for "Y" pizza for first even day
        while(evendays != 0){
            totalWeight += pizzas[i];
            i -= 2;
            evendays--;
        }
        return totalWeight;
    }
};
