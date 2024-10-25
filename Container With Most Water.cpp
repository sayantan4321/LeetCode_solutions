class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i=0, j=n-1;
        int maxwater=0;
        while(i<j){
            int width =j-i;
            int high= min(height[i], height[j]);
            int area= high*width;
            maxwater= max(maxwater, area);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxwater;
        // int maxi= INT_MIN;
        // int n= height.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int area = min(height[i], height[j])*(j-i);
        //         maxi = max(maxi, area);
        //     }
        // }
        // return maxi;
    }
};
