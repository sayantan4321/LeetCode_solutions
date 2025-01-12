class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // To store the maximum frequency of each character in words2
        
        // Calculate the maximum frequency of each character across all words in words2
        for (string word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        vector<string> ans;
        
        // Check each word in words1 against maxFreq
        for (string word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            
            // Verify if word meets the universal criteria
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                   isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(word);
            }
        }
        
        return ans;
        // vector<string> ans;
        // vector<int> arr(26, 0);

        // for(string ch: words2){
        //    for(int i=0; i<ch.length(); i++){
        //         arr[ch[i]-'a']++;
        //    }
        // }
        // for(string ch: words1){
        //    for(int i=0; i<ch.length(); i++){
        //         arr[ch[i]-'a']--;
        //    }
        //    for(int i=0; i<26; i++){
        //         if(arr[i] >0) break;
        //         else{
        //             ans.push_back(ch);
        //         }
        //     }
        // }
        // return ans;
    }
};
