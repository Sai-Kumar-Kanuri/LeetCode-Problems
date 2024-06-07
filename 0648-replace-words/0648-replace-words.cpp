struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie{
    private:
    Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;

        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word){
        
        Node *node = root;

        for(auto it: word){
            if(!node->containsKey(it)){
                return false;
            }
            node=node->get(it);
        }

        return node->isEnd();
    }

    string getWord(string word){
        Node *node = root;
        string prefix = "";
        for(auto it : word){
            if(node->containsKey(it)){
                prefix+=it;
                node = node->get(it);
                if(node->isEnd()){
                    return prefix;
                }
            }else{
                break;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        Trie *trie = new Trie();

        for(auto it : dictionary){
            trie->insert(it);
        }

        string ans = "",word;

        stringstream str(sentence);

        while(str>>word){
            ans+=trie->getWord(word)+" ";
        }

        ans.pop_back();

        return ans;
    }
};