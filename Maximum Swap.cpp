T.C. -> O(N)
S.C. -> O(N)
    
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int> rightmax(n);
        rightmax[n-1] = n-1;
        
        for(int i=n-2; i>=0; i--){
            int rightmaxIdx = rightmax[i+1]; // stores the right max element
            int rightmaxEle = str[rightmaxIdx];

            rightmax[i] = (str[i] > rightmaxEle) ? i : rightmaxIdx; 
        }
        for(int i=0; i<n; i++){
            int maxrightIdx = rightmax[i];
            int maxrightEle = str[maxrightIdx];
            if(str[i] < maxrightEle){
                swap(str[i], str[maxrightIdx]);
                return stoi(str);
            }
        }
        return num;
        
    }
};
