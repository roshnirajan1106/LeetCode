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
    void clone(Node*node, map<Node*,int>&visited, map<Node*,Node*>&maping)
    {
        if(node == NULL)
        {
            maping[node] =NULL;
            return ;
        }
        visited[node] = 1;
        Node*n = new Node();
        maping[node] = n;
        n->val = node->val;
        vector<Node*>v;
        for(auto p : node->neighbors){
            if(visited[p] == 0)
                clone(p,visited,maping);
            
            v.push_back(maping[p]);
        }
        n->neighbors = v;
            
    }
    Node* cloneGraph(Node* node) {
        map<Node*,int>visited;
        map<Node*,Node*>maping;

        clone(node,visited,maping);
        return maping[node];
        
    }
};