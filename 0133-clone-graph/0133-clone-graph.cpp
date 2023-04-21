/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>copies;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        Node* copy = new Node(node->val,{});
        queue<Node*>q;
        q.push(node);
        copies[node]=copy;
        
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            
            for(auto neighbor: curr->neighbors)
            {
                if(copies.find(neighbor)==copies.end())
                {
                    copies[neighbor]=new Node(neighbor->val,{});
                    q.push(neighbor);
                }
                copies[curr]->neighbors.push_back(copies[neighbor]);
            }
        }
        
        return copy;
        
    }
};