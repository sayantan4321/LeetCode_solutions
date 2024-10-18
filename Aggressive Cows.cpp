bool canWePlace(vector<int> &stalls, int distance, int cows){
    int cntCows = 1,  lastcow = stalls[0];

    for(int i=1; i<stalls.size(); i++){
       if(stalls[i]-lastcow >= distance){
           cntCows++;
           lastcow = stalls[i];
       }
       if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int n=stalls.size();

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
    // int limit = stalls[n - 1] - stalls[0];
    // for(int i=1; i<=limit; i++){

    //     if(canWePlace(stalls, i, k) ==true){
    //         continue;
    //     }
    //     else return  i-1;
    // }
    // return limit;
    
}