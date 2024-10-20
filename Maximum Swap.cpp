class Solution {
public:
    int maximumSwap(int num) {
        
        string str = to_string(num);
        int maxNum = num;
        for(int i=0; i<str.length(); i++){
            for(int j=i+1; j<str.length(); j++){
                int digit1 = str[i] - '0';
                int digit2 = str[j] - '0';
                if(digit1 < digit2 ){
                    swap(str[i], str[j]);
                }
                maxNum = max(maxNum, stoi(str));
                swap(str[i], str[j]); // **** swap back ****
            }
        }
        return maxNum;
    }
};
