class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n =  points.size();
        sort(points.begin(), points.end());
 
        vector<int> prev = points[0];
        int count =1;
        for(int i=1; i<n; i++){
           int currStartpoint = points[i][0];
           int currEndpoint = points[i][1];

           int prevStartpoint = prev[0];
           int prevEndpoint = prev[1];

           if(currStartpoint > prevEndpoint){ // non overlap
              count++;
              prev = points[i]; // curr is now new--> prev 
           }
           else{ // overlap
               prev[0] = max(prevStartpoint, currStartpoint);
               prev[1] = min(prevEndpoint, currEndpoint);
           }
        }
        return count;
    }
};