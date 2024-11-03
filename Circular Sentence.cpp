// Approach - 1
T.C. -> O(N)
S.C. -> O(1) 

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int size = sentence.length();

        for(int i=0; i<size; i++){ // 2nd check
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]){
                return false ;
            }
        }
        return sentence[0] == sentence[size-1]; // 1st  check 
    }
};
