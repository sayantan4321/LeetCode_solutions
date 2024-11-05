--------- Approach - 1 --------
// simply Insert the newInterval and Merge (Brute)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1]= max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;  
        
    }
};
--------- Approach -2 ------------
// Using O(N) space top reduce the complexity of vector oparetions 
// Optimal Approach
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> result; 
        int i = 0;
    
        // Add intervals that come before the new interval
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        // Merge overlapping intervals
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        
        // Add intervals that come after the new interval
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
