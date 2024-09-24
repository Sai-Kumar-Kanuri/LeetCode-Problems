struct Node {
   
    Node* links[10]; 
   
    bool flag = false;  

   
    bool containsKey(char ch) {
        return (links[ch -'0'] != nullptr); 
    }

  
    Node* get(char ch) {
        return links[ch -'0']; 
    }

   
    void put(char ch, Node* node) {
        links[ch -'0'] = node;  
    }

    
    void setEnd() {
        flag = true; 
    }

    
    bool isEnd() {
        return flag;  
    }
};


class Trie {
private:
   
    Node* root;  

public:
   
    Trie() {
        root = new Node();  
    }

   
    void insert(string num) {
         
        Node* node = root; 
        for (char ch : num) {  
             
            if (!node->containsKey(ch)) { 
              
                node->put(ch, new Node()); 
            }
    
            node = node->get(ch);  
        }
     
        node->setEnd(); 
    }

   
    int f(int num){

        Node* node = root;
        string numStr = to_string(num);
        int len = 0;

        for(auto it : numStr){
            if(node->containsKey(it)){
                len++;
                node=node->get(it);
            }else{
                break;
            }
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        Trie *trie = new Trie();

        for(auto it:arr1){
            trie->insert(to_string(it));
        }

        int longestPrefix = 0;

        for(auto it : arr2){
            longestPrefix = max(longestPrefix,trie->f(it));
        }

        return longestPrefix;

    }
};