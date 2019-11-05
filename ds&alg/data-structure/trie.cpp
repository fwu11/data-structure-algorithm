
class TrieNode{
public:
    vector<TrieNode*> children;
    bool is_word;
    TrieNode(){
        is_word = false;
        children = vector<TrieNode*>(26,NULL);
    }
};
 
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        // initialize the root node
        root = new TrieNode();
    }
    
    void insert(string &word) {
        TrieNode *node = root;
        for(char c : word){
            //check if the character is already in the trie
            if(node->children[c-'a'] == NULL){
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->is_word = true;
    }
    
    //if the word is in the trie.
    // can be modified to check the prefix
    bool find(string &word) {
        TrieNode *node = root;
        for(char c : word){
            //check if the character is already in the trie
            if(node->children[c-'a'] == NULL){
                return NULL;
            }
            node = node->children[c-'a'];
        }
        return node->is_word;
    }
};