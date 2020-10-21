//Day 20
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
    Node* cloneGraph(Node* src) {
        if(src==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        queue<Node*>q;
        q.push(src);
        
        Node *node = new Node();
        node->val = src->val;
        mp[src]=node;
        
        while(q.empty()==false){
            Node *u = q.front();
            q.pop();
            vector<Node*> v = u->neighbors;
            
            int n = v.size();
            for(int i=0;i<n;i++){
                if(mp[v[i]]==NULL){
                    node = new Node();
                    node->val = v[i]->val;
                    mp[v[i]]=node;
                    q.push(v[i]);
                }
                
                mp[u]->neighbors.push_back(mp[v[i]]);
            }
        }
        
        return mp[src];
    }
};
