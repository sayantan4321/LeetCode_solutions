--------- Approach - 1 ------------
T.C. -> O(N)
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0, i=0;

        while(i<n){
            char cur_char=chars[i];
            int count=0;
            while(i<n && chars[i]==cur_char){
                count++;
                i++;
            } 
            chars[index] = cur_char; // assigning first char at 0
            index++; // Increment to store its count(in string) 
            string str = to_string(count);

            if(count>1){
                for(auto it: str){
                    chars[index]=it;
                    index++; // if count is more than 10 we have two characters.
                }
            }

        }
        return index;

    }
};
