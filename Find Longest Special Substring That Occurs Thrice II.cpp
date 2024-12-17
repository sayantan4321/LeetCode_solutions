// Most Optimal Approach for each Lowe case char creating a matrix
// T.C. -> O(N)
// S.C. -> O(N)

class Solution {
public:
    int maximumLength(string s) { // High Constrains
        int n = s.length();
        vector<vector<int>> matrix(26, vector<int>(n+1, 0));
        
        char prev_char = s[0];
        int length = 0;

        for(int i=0; i<n; i++){
            char curr_char = s[i];
            if(curr_char == prev_char){
                length +=1;
                matrix[curr_char -'a'][length] +=1;
            }
            else{
                length = 1; // different char
                matrix[curr_char -'a'][length] +=1;
                prev_char = curr_char;
            }
        }
        int result = 0;
        for(int i=0; i<26; i++){
            int cummSum = 0;
            for(int j=n; j>=0; j--){
                cummSum += matrix[i][j];
                if(cummSum >= 3){
                    result = max(result, j);
                    break;
                }
            }
        }
        return result == 0 ? -1:result;
    }
};
