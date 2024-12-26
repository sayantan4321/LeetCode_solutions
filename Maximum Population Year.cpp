class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[101] = {0};
        for(vector<int> log: logs){
            arr[log[0]-1950]++;
            arr[log[1]-1950]--;
        }
        int max = 0;
        int cnt=0, year;
        for(int i=0; i<101; i++){
            cnt += arr[i];
            if(cnt > max){
                max = cnt;
                year = i;
            }
        }
        return year+1950;
    }
};
