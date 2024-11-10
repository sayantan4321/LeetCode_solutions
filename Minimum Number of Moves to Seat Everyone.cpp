// T.C. ->O(NlogN)
// S.c. -> O(1)
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int cnt=0;
        for(int i=0; i<seats.size(); i++){
            if(seats[i] > students[i]){
                cnt += abs(seats[i]-students[i]);
            }
            else if(seats[i] < students[i]){
                cnt += abs(seats[i]-students[i]);
            }
        }
        return cnt;
    }
};
