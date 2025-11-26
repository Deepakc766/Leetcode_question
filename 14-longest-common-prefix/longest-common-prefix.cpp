class TrieNode{
public:
    char value; 
    TrieNode* children[26]; 
    bool isEndOfWord; 
    TrieNode(char val){
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr; 
        }
        value = val; 
        isEndOfWord = false; 
    }
 void insert(TrieNode* root,string word){
    if(word.empty()) {
        root->isEndOfWord = true;
        return;
    }
    int index=word[0]-'a';
    if(root->children[index] == nullptr) {
        root->children[index] = new TrieNode(word[0]); 
        root= root->children[index];

    }else{
        root = root->children[index]; 
    }
    insert(root, word.substr(1)); 
 }

};
void lcp(TrieNode* root,string &output){
    if(root->isEndOfWord)return;
    int count=0;
    int i=-1;
  for(int index=0;index<26;index++){
    if(root->children[index]){
        ++count;
        i=index;
    }
    
  }
  if(count != 1){
    return;
  }else{
    output.push_back(char(i+'a'));
    lcp(root->children[i],output);
  }

}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
    TrieNode* root=new TrieNode('\0');
    for(auto str:strs){
        root->insert(root,str);
    }
    string output="";
    lcp(root,output);

    return output;
    }
};