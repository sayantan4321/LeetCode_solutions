/* 
Approach - 1
Using Set and rechare with substing  
T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
S.C : O(n*l + m*l)
*/
    
class Solution {
public:
    string findroot(string &word, unordered_set<string> &st){
        for(int i=0; i<word.length(); i++){
            string root = word.substr(0, i);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(begin(dictionary), end(dictionary));

        stringstream ss(sentence);
        string word; // to  get the every word of the above string
        string res;
        while(getline(ss, word, ' ')) {
            res += findroot(word, st) + " ";
        }
        res.pop_back(); // to remove last extra space
        return res;
    }
};
// Approach - 2
// using TRIE

//T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l + m*l)

class Solution {
public:
    struct trieNode{
        trieNode *children[26];
        bool isEnd;
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;

        for(int i=0; i<26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    trieNode* root; // Globally declared head of TRIE
    void insert(string word){
        trieNode* crawler = root;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';

            if(crawler->children[idx]==NULL){ // if no children was present at that index of the parent Node. 
                crawler->children[idx] =  getNode();  // creating New Node
            }
            crawler = crawler->children[idx]; // moving the ptr to next node for creating new Node or to End.
        }
        crawler->isEnd = true;
    }
    string search(string word){ // finding Shortest Route -> e.g. cattle, rattled, battery
        trieNode* crawler = root;

        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';

            if(crawler->children[idx]==NULL){// if first index in not present in the TRIE, then the word itself not Present
                return word;
            }
            crawler = crawler->children[idx];
            if(crawler->isEnd == true){
                return word.substr(0, i+1); // shortest root of the word.
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = getNode(); // creating Root Node
        for(string &word: dictionary){
            insert(word);
        }
        stringstream ss(sentence);
        string word; // to  get the every word of the above string
        string res;
        while(getline(ss, word, ' ')) {
            res += search(word) + " ";
        }
        res.pop_back(); // to remove last extra space
        return res;
    }
};
