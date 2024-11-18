// B.S. on Answers
// T.C. -> O(Log(1E7)∗N)
// S.C. -> O(1)    

class Solution {
public:
    double speed(vector<int>& dist, int speed){
        double time = 0.0;
        int n = dist.size();
        
        for(int i = 0; i < n - 1; i++) {
            double t = (double)dist[i]/(double)speed;
            time += ceil(t);           
        }
        time += (double)dist[n-1]/(double)speed; // for lasr we can add decimal only 
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7; // (int)(ceil(hour));
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(speed(dist, mid) <= hour){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
