class Solution {
public:
    // long long cntVowels(string str){
    //     long long vowelCount = 0; // Initialize the vowel count
    //     for (char ch : str) {
    //         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
    //             vowelCount++;
    //         }
    //     }
    //     return vowelCount;
    // }
    long long countVowels(string word) {
        // long long result =0;
        // int n = word.length();

        // for(int i=0; i<n; i++){
        //     long long cnt=0;
        //     for(int j=i; j<n; j++){
        //         string sub= word.substr(i,j);
        //         cnt += cntVowels(sub);
        //     }
        //     result += cnt;
        // }
        // return result;
        long long result = 0;
        long long n = word.length();

        for (int i = 0; i < n; ++i) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                // Calculate the number of substrings in which word[i] appears
                result += (i + 1) * (n - i);
            }
        }
        return result;
    }
};
