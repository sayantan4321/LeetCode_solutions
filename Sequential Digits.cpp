class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s= "123456789";
        vector<int> arr;

        for(int len=2; len<=s.length(); len++){
            for(int i=0; i<= s.length()-len; i++){
                string temp = s.substr(i,len);
                int ans= stoi(temp);

                if(ans>= low && ans<=high) arr.push_back(ans);
            }
        }
        return arr;
    }
};